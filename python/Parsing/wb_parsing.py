import requests
import json
from urllib.parse import urlencode

value = "чехол на айфон"
sort = 'popular' # popular, pricedown, priceup, newly, benefit
search = {'query': value}
queryString = urlencode(search)
print(queryString)

url = f"https://search.wb.ru/exactmatch/ru/common/v7/search?ab_testing=false&appType=1&curr=rub&dest=-2133466&{queryString}&resultset=catalog&sort={sort}&spp=30&suppressSpellcheck=false"
headers = {'Accept': "*/*", 'User-Agent':"Mozilla/5.0 (Windows NT 10.0; Win64; x64)"}
response = requests.get(url, headers=headers)
data = response.json()

with open('wb_catalogs_data.json', 'w', encoding='UTF-8') as file:
    json.dump(data, file, indent=2, ensure_ascii=False)
    print(f'Данные сохранены в wb_catalogs_data.json')

def get_links_photo(id):
    real_id = id
    id = id // 100_000
    if (id >= 0 and id <= 143):
        r = "01"
    elif(id <= 287):
        r = "02";    
    elif(id <= 431):
        r = "03";    
    elif(id <= 719):
        r = "04";    
    elif(id <= 1007):
        r = "05"
    elif(id <= 1061):
        r = "06"
    elif(id <= 1115):
        r = "07"
    elif(id <= 1169):
        r = "08"
    elif(id <= 1313):
        r = "09"
    elif(id <= 1601):
        r = "10"
    elif(id <= 1655):
        r = "11"
    elif(id <= 1919):
        r = "12"
    elif(id <= 2045):
        r = "13"
    elif(id <= 2189):
        r = "14"
    elif(id <= 2405):
        r = "15"
    elif(id <= 2621):
        r = "16"
    elif(id <= 2837):
        r = "17"
    elif(id <= 3053):
        r = "18"
    elif(id <= 3269):
        r = "19"
    elif(id <= 3485):
        r = "20"
    else: r = "21"
    return f"https://basket-{r}.wbbasket.ru/vol{real_id // 100_000}/part{real_id // 1_000}/{real_id}/images/big/1.webp"

def get_data_from_json(json_file):
    data_list = []
    for data in json_file['data']['products']:
        try:
            price = data['sizes'][0]['price']['product'] // 100
        except:
            price = 0
        data_list.append({
            "Name": data['name'],
            "Brand": data['brand'],
            "ID Brand": data['brandId'],
            "ID": data['id'],
            "Price": price,
            "Feedback": data['feedbacks'],
            "Rating": data['reviewRating'],
            "Card link": f"https://www.wildberries.ru/catalog/{data['id']}/detail.aspx",
            "Preview": get_links_photo(data['id']) 
        })
    return data_list

wb_data = get_data_from_json(data)
with open('wb_data.json', 'w', encoding='UTF-8') as file:
    json.dump(wb_data, file, indent=2, ensure_ascii=False)
    print(f'Данные сохранены в wb_data.json')
