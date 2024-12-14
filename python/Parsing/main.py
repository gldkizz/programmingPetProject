from bs4 import BeautifulSoup
import requests

st_accept = "text/html"
st_useragent = "Mozilla/5.0 (Macintosh; Intel Mac OS X 12_3_1) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/15.4 Safari/605.1.15"
headers = {
    "Accept": st_accept,
    "User-agent": st_useragent
}
url = 'https://market.yandex.ru/catalog--aksessuary-dlia-zhenshchin/54360041/list?rs=eJwzMnnByPiJUY-DUWDhIVYJBo03CyZKajSfZNV48eIOs8avbVIaj0GMF3ems2vM3A0kfgAVOBVyKXKxcTBKMCowCghI8eQmppTFF2ek5qTFGyrsaeHSaOw9zghVwqvAgqbEWOHbS06No513GLnUwUpkFTiASoSQlBjFFySmpxopPHnHo7Go6RajAJMXR6plqkWqQXJakJGhubGxmamRqYmJpbmpvnFiSoqZmYlxmoGhhaGRoaVZirmJYZK5QVKakYWBmYGBvqG-IQCid0Tr'
req = requests.get(url, headers)
src = req.text

soup = BeautifulSoup(src, 'html.parser')
salary = soup.find('span','ds-text ds-text_weight_bold ds-text_color_price-term ds-text_typography_headline-5 ds-text_headline-5_tight ds-text_headline-5_bold')
name = soup.find('span','ds-text ds-text_lineClamp_2 ds-text_weight_med ds-text_color_text-primary ds-text_typography_text ds-text_text_normal ds-text_text_med ds-text_lineClamp')
delivery = soup.find('span','_1yLiV')
print(salary.text, name.text, delivery.text)



