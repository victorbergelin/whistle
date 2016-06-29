
main_path =  '/Users/victorbergelin/Dropbox/Repo/whistle';
cd(main_path);


Array=csvread('dft.csv');
hold on
subplot(2,1,1)
plot(Array)
subplot(2,1,2)
hist(Array,200)
hold off


%%

[y1,Fs] = audioread('whistle1.wav');
[y2,Fs] = audioread('whistle2.wav');
[y3,Fs] = audioread('whistle3.wav');

Y1 = fft(y1);