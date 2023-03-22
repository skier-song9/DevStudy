# 📢 상관분석
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

w=pd.read_csv("./data/chi_weight.txt")
w.head(2)
w.corr()

sns.heatmap(w.corr(),annot=True, cmap='Accent')
#plt.show()

# sns.pairplot(w)
sns.pairplot(w[['weight','egg_weight','movement','food']])
plt.show()