from selenium import webdriver
import time
import json
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.chrome.options import Options
from functions import collect_product_info
from functions import page_down

def find_products_links(item_name = "ковёр"):
    # o = Options()
    # o.add_experimental_option("detach", True)
    options = webdriver.ChromeOptions()
    options.headless = True
    options.add_argument('--disable-blink-features=AutomationControlled')
    driver = webdriver.Chrome(options=options)
    driver.implicitly_wait(5)
    driver.get('http://ozon.ru')
    time.sleep(2)

    # driver.find_element(By.CLASS_NAME, 'rb').click()
    # time.sleep(2)
    find_input = driver.find_element(By.NAME, 'text')
    find_input.clear()

    find_input.send_keys(item_name)
    time.sleep(1)

    find_input.send_keys(Keys.ENTER)
    time.sleep(1)

    try:
        page_down(driver=driver)
        time.sleep(4)
        find_links = driver.find_elements(By.CLASS_NAME, "tile-hover-target")
        products_urls = list(set([f'{link.get_attribute("href")}' for link in find_links]))
        print("[+] Ссылки собраны")
    except:
        print("[!] Ссылки не собраны")

    products_urls_dict = {}

    for k, v in enumerate(products_urls):
        products_urls_dict.update({k: v})
    with open('ozon_urls.json', 'w', encoding='UTF-8') as file:
        json.dump(products_urls_dict, file, indent=2, ensure_ascii=False)
        print(f'Данные сохранены в ozon_urls.json')


    time.sleep(1)
    product_data = []
    for url in products_urls:
        data = collect_product_info(driver=driver, url = url)
        if(data == 0):
            continue
        print(f"[+]Собрал данные продукта с id:{data.get("product_id")}")
        time.sleep(1)
        product_data.append(data)
    with open('ozon_data.json', 'w', encoding='UTF-8') as file:
        json.dump(product_data, file, indent=2, ensure_ascii=False)
        print(f'Данные сохранены в ozon_data.json')


    driver.close()
    driver.quit()

def main():
    find_products_links()

if __name__ == '__main__':
    main()

