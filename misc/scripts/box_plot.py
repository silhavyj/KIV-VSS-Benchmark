import json
import matplotlib.pyplot as plt
import numpy as np
import statistics


with open('../measured_data/middle.json', 'r') as file:
    json_data = json.load(file)

keys = []
for size in json_data:
    keys.append(int(size))
    
keys.sort()

data_a = []
data_b = []
ticks = []

for size in keys:
    size = str(size)
    data_a.append(statistics.median(json_data[size]['vector']))
    data_b.append(statistics.median(json_data[size]['list']))
    ticks.append(str(size) + "B")
    
print(data_a)
print(data_b)