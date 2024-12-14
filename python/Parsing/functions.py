from selenium import webdriver
import time
from selenium.webdriver.common.by import By
import re

def page_down(driver):
    driver.execute_script('''
                            const scrollStep = 200;
                            const scrollInterval = 100;
                          
                            const scrollHeight = document.documentElement.scrollHeight;
                            let currentPosition = 0;
                            const interval = setInterval(() => {
                                window.scrollBy(0, scrollStep);
                                currentPosition += scrollStep;
                          
                                if(currentPosition >= scrollHeight) {
                                    clearInterval(interval);
                                }
                            },scrollInterval)
                          ''')

def collect_product_info(driver, url=''):
    driver.switch_to.new_window('tab')

    time.sleep(1)
    driver.get(url=url)
    time.sleep(1)
    # try: 
    #     check = driver.find_element(By.XPATH, '//*[@id="layoutPage"]/div[1]/div[2]/div[1]/div/div[2]/div[1]/div[1]/h2').text
    #     if(check == 'Этот товар закончился'):
    #         print("Товар закончился, пропускаем")
    #         driver.close()
    #         driver.switch_to.window(driver.window_handles[0])
    #         return 0
    # except:
    #     pass
    
    product_id = driver.find_element(By.XPATH, '//div[contains(text(), "Артикул: ")]').text.split('Артикул: ')[1]

    product_name = driver.find_element(By.TAG_NAME,'h1').text

    price_with_card = driver.find_element(By.XPATH, '//span[contains(text(), " ₽")]').text[:-2].replace(' ', '')

    rating = driver.find_element(By.TAG_NAME,'h1').find_element(By.XPATH,'//following::div/a/div').text.split(' • ')[0]

    feedbacks = driver.find_element(By.TAG_NAME,'h1').find_element(By.XPATH,'//following::div/a/div').text.split(' • ')[1]
    feedbacks = re.findall(r'\b\d+\b',feedbacks)
    feedbacks = ''.join(feedbacks)

    delivery_date = driver.find_element(By.XPATH, '//span[text() = "Доставим "]/following::span').text

    product_data = ({
        'product_id': product_id,
        'product_name':product_name,
        'price_with_card':price_with_card,
        'rating': rating,
        'feedbacks': feedbacks,
        'delivery':delivery_date
    })
    driver.close()
    driver.switch_to.window(driver.window_handles[0])
    return product_data