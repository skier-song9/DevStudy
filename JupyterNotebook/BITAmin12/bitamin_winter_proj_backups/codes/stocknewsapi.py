import json

import requests as req

my_token = '6tbxlwdn3exj5eugyahnt9clnh9lsp7f82zruvrc'

ticker = 'NFLX'
output_numbers = 3
# for i in range(50):
page = 49
res = req.get(f'https://stocknewsapi.com/api/v1?tickers={ticker}&items={output_numbers}&page={page}&token={my_token}')
res_json = res.json()
pretty_json = json.dumps(res_json,indent=4)
print(pretty_json)

