api_token = 'prmmuumogvpgjupbkxhiucaskjzovxly'
api_url = 'https://codeweekend.dev:3721/api/'
files_url = 'https://codeweekend.dev:81/'
import requests
import json
import time
import os
from tqdm import tqdm

headers = {
    'authorization': f'Bearer {api_token}'
}

def show(inner_json):
    print(json.dumps(inner_json, indent=2))

def get_scoreboard():
    return requests.get(api_url + 'scoreboard', headers=headers).json()

def get_team_dashboard():
    return requests.get(api_url + 'team_dashboard', headers=headers).json()

def get_test(task_id):
    task_id_padded = '{:03d}'.format(task_id)
    url = f'{files_url}{task_id_padded}.json'
    return requests.get(url, headers=headers).content

# Returns at most 50 submissions
def get_team_submissions(offset=0, task_id=None):
    url = f'{api_url}team_submissions?offset={offset}'
    if task_id is not None:
      url += f'&task_id={task_id}'
    return requests.get(url, headers=headers).json()

def get_submission_info(submission_id, wait=False):
    url = f'{api_url}submission_info/{submission_id}'
    res = requests.get(url, headers=headers).json()
    if 'Pending' in res and wait:
        print('Submission is in Pending state, waiting...')
        time.sleep(1)
        return get_submission_info(submission_id)
    return res

# Returns submission_id
def submit(task_id, solution):
    res = requests.post(url = f'{api_url}submit/{task_id}',
                        headers=headers, files={'file': solution})
    if res.status_code == 200:
        return res.text
    print(f'Error: {res.text}')
    return None

for file in range(25,26):
	with open(f"output{file}.json", "r") as f:
	    id = submit(file, f)
	    print(f"Score for test {file} : ", get_submission_info(id))