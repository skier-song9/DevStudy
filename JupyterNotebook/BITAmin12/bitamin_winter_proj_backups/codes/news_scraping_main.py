from news_scraping.news_scraping_chrome import *
from tqdm import tqdm

# years = list(range(2018,2024))
# months = [[1,2,3],[4,5,6],[7,8,9],[10,11,12]]
years = [2022]
months = [[4,5,6]]

for year in years:
    for month in tqdm(months):
        articles_df = netflix_news_scraping_s2e(year,month)
        articles_df.to_csv(f'../data/scraping/articles_urls_0128_{year}_{month[0]}.csv')
print('end scraping')
