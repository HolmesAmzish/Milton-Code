import pandas as pd
import matplotlib.pyplot as plt
from scipy.stats import linregress

def load_data(file_path):
    data = pd.read_csv(file_path)
    print(data.info())
    print(data.describe())
    return data

def clean_data(data):
    data = data.dropna()
    data = data[data['DAILY_PRECIP'] < 5]
    data = data[data['DAILY_PRECIP'] > -1]
    print(data.describe())
    return data

def calculate_statistics(data):
    max_value = data['DAILY_PRECIP'].max()
    min_value = data['DAILY_PRECIP'].min()
    mean_value = data['DAILY_PRECIP'].mean()
    variance = data['DAILY_PRECIP'].var()
    median_value = data['DAILY_PRECIP'].median()
    return max_value, min_value, mean_value, variance, median_value

def plot_histogram(data):
    plt.hist(data['DAILY_PRECIP'], bins=30, color='blue', edgecolor='black')
    plt.title('Histogram of Daily Precipitation')
    plt.xlabel('Daily Precipitation')
    plt.ylabel('Frequency')
    plt.show()

def yearly_trends(data):
    data['DATE'] = pd.to_datetime(data['DATE'])
    data['Year'] = data['DATE'].dt.year
    yearly_avg_precipitation = data.groupby('Year')['DAILY_PRECIP'].mean()
    yearly_max_precipitation = data.groupby('Year')['DAILY_PRECIP'].max()
    plt.figure(figsize=(10, 5))
    plt.plot(yearly_avg_precipitation, label='Yearly Average Precipitation')
    plt.plot(yearly_max_precipitation, label='Yearly Maximum Precipitation')
    plt.legend()
    plt.title('Yearly Average and Maximum Precipitation Trends')
    plt.xlabel('Year')
    plt.ylabel('Precipitation')
    plt.show()

def scatter_plot_and_regression(data):
    plt.scatter(data['TEMPERATURE'], data['DAILY_PRECIP'], alpha=0.5)
    plt.title('Scatter Plot of Temperature vs. Precipitation')
    plt.xlabel('Temperature')
    plt.ylabel('Precipitation')
    plt.show()
    slope, intercept, r_value, p_value, std_err = linregress(data['TEMPERATURE'], data['DAILY_PRECIP'])
    print(f"Slope: {slope}, Intercept: {intercept}, R-squared: {r_value**2}")
    plt.scatter(data['TEMPERATURE'], data['DAILY_PRECIP'], alpha=0.5)
    plt.plot(data['TEMPERATURE'], slope * data['TEMPERATURE'] + intercept, color='red')
    plt.title('Linear Fit of Temperature vs. Precipitation')
    plt.xlabel('Temperature')
    plt.ylabel('Precipitation')
    plt.show()

def box_plot_by_station(data):
    data.boxplot(column='DAILY_PRECIP', by='STATION')
    plt.title('Box Plot of Precipitation by Station')
    plt.suptitle('')
    plt.xlabel('Station')
    plt.ylabel('Precipitation')
    plt.show()

def main():
    file_path = r'E:\\Milton-Code\\Projects\\Rain\\data.csv'
    data = load_data(file_path)
    data = clean_data(data)
    max_value, min_value, mean_value, variance, median_value = calculate_statistics(data)
    print(f"Max: {max_value}, Min: {min_value}, Mean: {mean_value}, Variance: {variance}, Median: {median_value}")
    plot_histogram(data)
    yearly_trends(data)
    scatter_plot_and_regression(data)
    box_plot_by_station(data)

if __name__ == "__main__":
    main()