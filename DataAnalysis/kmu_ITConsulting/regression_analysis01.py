import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import statsmodels.api as sm
from sklearn.model_selection import train_test_split
from sklearn import linear_model

w=pd.read_csv("./data/chi_weight.txt")
w.head(2)
w.corr()

X = w[['egg_weight','movement','food']]
y = w['weight']
X_train, X_test, y_train, y_test = train_test_split(X,y,test_size=0.2, random_state=0)

lr = linear_model.LinearRegression()
lr.fit(X_train,y_train)

print(lr.intercept_,lr.coef_,lr.score(X_train,y_train))
lr.score(X_test,y_test)
y_pred=lr.predict(X_test)

X_train_add_constant = sm.add_constant(X_train)
sm_lr_ac = sm.OLS(y_train,X_train_add_constant).fit()


# 훈련 결과 검증
print(sm_lr_ac.params)

sm_lr_ac.rsquared
print(sm_lr_ac.summary())


# 테스트 데이터 적용
SST = np.sum((y_test - y_test.mean())**2)

SSR = np.sum((y_pred - y_test)**2)

print("SST: ",SST, ", SSR: ",SSR, ", R Squar: ",1 - SSR/SST)

