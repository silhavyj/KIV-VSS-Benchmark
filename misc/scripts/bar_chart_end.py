import matplotlib.pyplot as plt
import numpy as np
import json
import statistics

with open('../measured_data/end.json', 'r') as file:
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
    data_a.append(round(statistics.median(json_data[size]['vector']), 1))
    data_b.append(round(statistics.median(json_data[size]['list']), 1))
    ticks.append(int(size) / 1024 / 1024)

office_expenses = data_a
travel_expenses = data_b
 
#bar chart properties
x = np.arange(len(ticks))
width = 0.3
 
#draw grouped bar chart
fig, ax = plt.subplots()
bar1 = ax.bar(x - width/2, travel_expenses, width, label='std::list')
bar2 = ax.bar(x + width/2, office_expenses, width, label='std::vector')
 
#ax.set_xlabel('Year')
ax.set_ylabel('Time of execution (removing all elements) [ms]')
ax.set_title('Removing elements from the end of the collection')
ax.set_xticks(x)
ax.set_xticklabels([round(tick, 2) for tick in ticks])
ax.set_axisbelow(True)
ax.grid(axis='y')
ax.set_xlabel('Collection size [MB]')
ax.legend()
 
#setting bar labels
ax.bar_label(bar1)
ax.bar_label(bar2)
 
fig.tight_layout()
 
plt.show()