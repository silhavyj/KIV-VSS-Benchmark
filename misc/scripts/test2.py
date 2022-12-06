import matplotlib.pyplot as plt
import numpy as np
 
#data
#x-axis
years = [2016, 2017, 2018, 2019, 2020, 2021]
#y-axis
office_expenses = [100, 150, 90, 70, 200, 120]
travel_expenses = [20, 40, 20, 50, 20, 10]
 
#bar chart properties
x = np.arange(years[0], years[-1] + 1)
width = 0.3
 
#draw grouped bar chart
fig, ax = plt.subplots()
bar1 = ax.bar(x - width/2, travel_expenses, width, label='Travel Expenses')
bar2 = ax.bar(x + width/2, office_expenses, width, label='Office Expenses')
 
#ax.set_xlabel('Year')
ax.set_ylabel('Expenses($)')
ax.set_title('Average expenses of ABC')
ax.set_xticks(x)
ax.set_xlabel('Collection size [B]')
ax.legend()
 
#setting bar labels
ax.bar_label(bar1)
ax.bar_label(bar2)
 
fig.tight_layout()
 
plt.show()