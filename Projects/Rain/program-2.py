# -*- coding: utf-8 -*-
"""
Created on Sun Jun 16 19:18:33 2024

@author: 34271
"""

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from sklearn.linear_model import LinearRegression

# 加载数据
file_path = r'E:\\Milton-Code\\Projects\\Rain\\data.csv'
df = pd.read_csv(file_path, encoding='utf-8')

# 显示数据的前几行，确认数据加载正确
print(df.head())

# 查看数据的基本信息，包括列名、非空值数量、数据类型等
print(df.info())
# 描述性统计信息
summary = df.describe()
print(summary)

# 查看缺失值情况
missing_values = df.isnull().sum()
print(missing_values)

# 查看各列的唯一值
for column in df.columns:
    print(f"Unique values in {column}: {df[column].unique()}")

df_cleaned = df[(df['DAILY_PRECIP']>=-1)&(df['DAILY_PRECIP']<=5)&
                  (df['TEMPERATURE']>=-50)&(df['TEMPERATURE']<=50)&
                  (df['HUMIDITY']>=20)&(df['HUMIDITY']<=80)]
df_cleaned['DATE']=pd.to_datetime(df_cleaned['DATE']) 
print(df_cleaned.describe())
# 统计值
statistics = df_cleaned.describe()
print(statistics)
plt.rcParams['font.sans-serif'] = ['SimHei']  # 使用黑体字体
plt.rcParams['axes.unicode_minus'] = False     # 正确显示负号
# 绘制2003年的温度分布图（直方图）
df_2003 = df_cleaned[df_cleaned['DATE'].dt.year == 2003]
plt.figure(figsize=(10, 6))
plt.hist(df_2003['TEMPERATURE'], bins=20, color='skyblue', edgecolor='black')
plt.title('2003年温度直方图')
plt.xlabel('温度')
plt.ylabel('Frequency')
plt.grid(True)
plt.show()
# 绘制2003年的降水量分布图（直方图）
df_2003 = df_cleaned[df_cleaned['DATE'].dt.year == 2003]
plt.figure(figsize=(10, 6))
plt.hist(df_2003['DAILY_PRECIP'], bins=20, color='yellow', edgecolor='black')
plt.title('2003年降水量直方图')
plt.xlabel('降水量')
plt.ylabel('Frequency')
plt.grid(True)
plt.show()
# 绘制2003年的湿度分布图（直方图）
df_2003 = df_cleaned[df_cleaned['DATE'].dt.year == 2003]
plt.figure(figsize=(10, 6))
plt.hist(df_2003['HUMIDITY'], bins=20, color='green', edgecolor='black')
plt.title('2003年湿度直方图')
plt.xlabel('HUMIDITY')
plt.ylabel('Frequency')
plt.grid(True)
plt.show()
# 求取处理后的这三列数据的最大值
max_daily_precip = df_cleaned ['DAILY_PRECIP'].max()
max_temperature = df_cleaned ['TEMPERATURE'].max()
max_humidity = df_cleaned ['HUMIDITY'].max()
print(f"Max Daily Precipitation: {max_daily_precip}")
print(f"Max Temperature: {max_temperature}")
print(f"Max Humidity: {max_humidity}")
# 求取处理后的这三列数据的最小值
min_daily_precip = df_cleaned ['DAILY_PRECIP'].min()
min_temperature = df_cleaned ['TEMPERATURE'].min()
min_humidity = df_cleaned ['HUMIDITY'].min()
print(f"Min Daily Precipitation: {min_daily_precip}")
print(f"Min Temperature: {min_temperature}")
print(f"Min Humidity: {min_humidity}")
# 求取处理后的这三列数据的均值
mean_daily_precip = df_cleaned ['DAILY_PRECIP'].mean()
mean_temperature = df_cleaned ['TEMPERATURE'].mean()
mean_humidity = df_cleaned ['HUMIDITY'].mean()
print(f"Mean Daily Precipitation: {mean_daily_precip}")
print(f"Mean Temperature: {mean_temperature}")
print(f"Mean Humidity: {mean_humidity}")
# 求取处理后的这三列数据的方差
var_daily_precip = df_cleaned ['DAILY_PRECIP'].var()
var_temperature = df_cleaned ['TEMPERATURE'].var()
var_humidity = df_cleaned ['HUMIDITY'].var()
print(f"Var Daily Precipitation: {var_daily_precip}")
print(f"Var Temperature: {var_temperature}")
print(f"Var Humidity: {var_humidity}")
# 求取处理后的这三列数据的中位数
median_daily_precip = df_cleaned ['DAILY_PRECIP'].median()
median_temperature = df_cleaned ['TEMPERATURE'].median()
median_humidity = df_cleaned ['HUMIDITY'].median()
print(f"Median Daily Precipitation: {median_daily_precip}")
print(f"Median Temperature: {median_temperature}")
print(f"Median Humidity: {median_humidity}")

# 按年份和测站分组计算统计数据
# 提取 DATE 列中的年份信息
df_cleaned['YEAR'] = df_cleaned['DATE'].dt.year

# 按 YEAR 和 STATION 分组
grouped = df_cleaned.groupby(['YEAR', 'STATION'])

# 每年每个测站的有效观测次数
observations_count = grouped.size().reset_index(name='OBSERVATION_COUNT')

# 每年每个测站的平均降水量
annual_mean_precipitation = grouped['DAILY_PRECIP'].mean().reset_index(name='MEAN_PRECIPITATION')

# 每年每个测站的最大降水量
annual_max_precipitation = grouped['DAILY_PRECIP'].max().reset_index(name='MAX_PRECIPITATION')

# 绘制温度和降水随时间变化的趋势图
stations = df_cleaned['STATION'].unique()

for station in stations:
    station_data = df_cleaned[df_cleaned['STATION'] == station]
    plt.figure(figsize=(12, 6))
    
    # 绘制温度
    plt.subplot(2, 1, 1)
    plt.plot(station_data['DATE'], station_data['TEMPERATURE'], marker='o', linestyle='-', color='b')
    plt.title(f'测站 {station} 的温度变化趋势')
    plt.xlabel('日期')
    plt.ylabel('温度 (°C)')
    plt.grid(True)
    
    # 绘制降水量
    plt.subplot(2, 1, 2)
    plt.plot(station_data['DATE'], station_data['DAILY_PRECIP'], marker='o', linestyle='-', color='g')
    plt.title(f'测站 {station} 的降水量变化趋势')
    plt.xlabel('日期')
    plt.ylabel('降水量 (mm)')
    plt.grid(True)
    
    plt.tight_layout()
    plt.show()

# 显示计算得到的统计数据
print("每年每个测站的有效降水观测次数:")
print(observations_count)

print("\n每年每个测站的平均降水量:")
print(annual_mean_precipitation)

print("\n每年每个测站的最大降水量:")
print(annual_max_precipitation)



df_cleaned['YEAR'] = df_cleaned['DATE'].dt.year
df_cleaned['MONTH'] = df_cleaned['DATE'].dt.month

# 按 YEAR、MONTH 和 STATION 分组
grouped = df_cleaned.groupby(['YEAR', 'MONTH', 'STATION'])

# 每个月每个测站的平均温度和降水量
monthly_avg = grouped.agg({'TEMPERATURE': 'mean', 'DAILY_PRECIP': 'mean'}).reset_index()

# 绘制每个测站月平均温度和降水量随时间变化的趋势图
stations = df_cleaned['STATION'].unique()

for station in stations:
    station_data = monthly_avg[monthly_avg['STATION'] == station]
    
   # 绘制月平均温度变化趋势图
    plt.figure(figsize=(12, 6))
    plt.plot(station_data['YEAR'] + station_data['MONTH']/12, station_data['TEMPERATURE'], marker='o', linestyle='-', color='b')
    plt.title(f'测站 {station} 的月平均温度变化趋势')
    plt.xlabel('时间 (年)')
    plt.ylabel('月平均温度 (°C)')
    plt.grid(True)
    plt.xticks(station_data['YEAR'].unique() + station_data['MONTH'].unique()/12, rotation=45)
    plt.tight_layout()
    plt.show()
    
    # 绘制月平均降水量变化趋势图
    plt.figure(figsize=(12, 6))
    plt.plot(station_data['YEAR'] + station_data['MONTH']/12, station_data['DAILY_PRECIP'], marker='o', linestyle='-', color='g')
    plt.title(f'测站 {station} 的月平均降水量变化趋势')
    plt.xlabel('时间 (年)')
    plt.ylabel('月平均降水量 (mm)')
    plt.grid(True)
    plt.xticks(station_data['YEAR'].unique() + station_data['MONTH'].unique()/12, rotation=45)
    plt.tight_layout()
    plt.show()
    
    
    plt.figure(figsize=(10, 6))
plt.scatter(df_cleaned['TEMPERATURE'], df_cleaned['DAILY_PRECIP'], alpha=0.6)
plt.title('测站温度与降水之间的关系')
plt.xlabel('平均温度 (°C)')
plt.ylabel('平均降水量 (mm)')
plt.grid(True)

# 如果存在线性关系，进行线性拟合
# 使用 sklearn 的 LinearRegression 拟合线性关系
X = df_cleaned['TEMPERATURE'].values.reshape(-1, 1)
y = df_cleaned['DAILY_PRECIP'].values.reshape(-1, 1)

model = LinearRegression()
model.fit(X, y)

# 绘制拟合直线
plt.plot(X, model.predict(X), color='red', linewidth=2)

# 打印线性回归方程
slope = model.coef_[0]
intercept = model.intercept_
equation = f'降水量 = {slope:.2f} * 温度 + {intercept:.2f}'
plt.text(0.05, 0.95, equation, transform=plt.gca().transAxes, fontsize=12, verticalalignment='top')

plt.show()