import pandas as pd
#📢 시리즈 : 데이터가 순차적으로 나열된 1차원 배열이다.
#   - 파이썬의 딕셔너리와 비슷하다.
#   - key : value쌍으로 데이터가 저장된다. key값을 지정하지 않으면 인덱스로 자동 지정된다.
#           >> key(=인덱스 이름)은 option이고, 정수형 위치 인덱스는 default이다.
#   🔔Series()생성자 함수의 위치인자로 index=[배열]을 전달하면 인덱스 이름을 지정할 수 있다.

# 🔔시리즈 만들기1] pd.Series() : 딕셔너리 >> 시리즈
dict_ = {'a':1,'b':2,'c':3}
se_dict = pd.Series(dict_)
# print(se_dict,type(se_dict),sep="\n")
'''
a    1
b    2
c    3
dtype: int64
<class 'pandas.core.series.Series'>
'''
# 🔔시리즈 만들기2] pd.Series() : 리스트 >> 시리즈
list_ = ['가','나','다']
se_list = pd.Series(list_)
# print(se_list,type(se_list),sep="\n")
'''
0    가
1    나
2    다
dtype: object
<class 'pandas.core.series.Series'>
'''
# 🔔시리즈 만들기3] pd.Series() : 튜플 >> 시리즈
tuple_ = ('철수','2020-01-23','남',True)
se_tuple = pd.Series(tuple_,index=['이름','날짜','성별','학생여부']) # index 위치인자로 인덱스 이름 지정하기.
# print(se_tuple,type(se_tuple),sep="\n")
'''
0            철수
1    2020-01-23
2             남
3          True
dtype: object
<class 'pandas.core.series.Series'>
'''

# 📢시리즈 클래스의 주요 속성
# 시리즈객체.index : 시리즈객체의 인덱스를 담은 인덱스객체를 반환한다. >> __iter__ 없음.
sdi=se_dict.index
sli=se_list.index
# print('se_dict.index: ',sdi) #Index(['a', 'b', 'c'], dtype='object')
# print('se_list.index: ',sli) #RangeIndex(start=0, stop=3, step=1)
# print(type(sdi)) # <class 'pandas.core.indexes.base.Index'>
# print(type(sli)) # <class 'pandas.core.indexes.range.RangeIndex'>

# 시리즈객체.values : 시리즈객체의 value를 담은 배열(ndarray)을 반환한다.
sdv=se_dict.values
slv=se_list.values
# print('se_dict.values: ',sdv) #[1 2 3]
# print('se_list.values: ',slv) #['가' '나' '다']
# print(type(sdv)) # <class 'numpy.ndarray'>
# print(type(slv)) # <class 'numpy.ndarray'>

# 📢시리즈 객체의 요소에 접근하기
# 1] 위치 인덱스로 접근하기
# print(se_dict[1]) # 2
# 2] 인덱스 이름(key)으로 접근하기 (큰따옴표, 작은따옴표 상관 없음.)
# print(se_dict['b']) # 2
# 3] 여러 개의 요소에 접근하기 >> 1번,2번을 '배열'로 전달한다.
#   >> 🔔새로운 시리즈 객체로 반환한다.
print(se_tuple[['이름','성별']])
print(se_list[[0,1]])
# 4] 슬라이싱으로 접근하기 >> 🔔새로운 시리즈 객체로 반환한다.
print(se_tuple[0:])
