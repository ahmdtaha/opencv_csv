bgr = csvread('brg_img.csv');
num_cols = 100;
num_rows = 100;
num_channels = 3;

%% Sometimes when the saved mat is very big, csvread read the file as a single row
%% In such case,you will need the following line to fix the dimensions of the matr
%bgr  = reshape(bgr,[num_channels*num_cols,num_rows])';

blue_channel = bgr(:,1:num_channels:end);
green_channel = bgr(:,2:num_channels:end);
red_channel = bgr(:,3:num_channels:end);
figure;imshow(uint8(blue_channel));title('Blue Channel');
figure;imshow(uint8(green_channel));title('Green Channel');
figure;imshow(uint8(red_channel));title('Red Channel');

%bgr  = bgr (:,1:num_channels:end)+bgr (:,3:num_channels:end) .* i; %% Convert it from double to complex array

gray = csvread('single_img.csv');
figure;imagesc(gray);title('Gray Image')