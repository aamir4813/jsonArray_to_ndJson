import json

with open('./movies.json') as f:
    data = json.load(f)

    required_data = ''

    for i in range(len(data)):
        header = {"index": {"_index": "movies", "_type": "movie", "_id": i+1}}
        required_data += json.dumps(header)
        required_data += '\n'
        required_data += json.dumps(data[i])
        required_data += '\n'

    print(required_data)