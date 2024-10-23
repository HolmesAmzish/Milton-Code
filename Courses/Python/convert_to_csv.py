import sys
import re

def convert_to_csv(input_file):
    output_file = input_file.replace('.csv', '_converted.csv')
    
    with open(input_file, 'r', encoding='utf-8') as infile, open(output_file, 'w', encoding='utf-8') as outfile:
        for line in infile:
            # 使用正则表达式替换多个空白符为逗号
            new_line = re.sub(r'\s+', ',', line.strip())
            outfile.write(new_line + '\n')
    
    print(f'Converted file saved as: {output_file}')

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: python script.py <input_file.csv>")
        sys.exit(1)
    
    input_filename = sys.argv[1]
    convert_to_csv(input_filename)
