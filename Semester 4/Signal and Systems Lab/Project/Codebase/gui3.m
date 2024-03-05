function varargout = gui3(varargin)
% GUI3 MATLAB code for gui3.fig
%      GUI3, by itself, creates a new GUI3 or raises the existing
%      singleton*.
%
%      H = GUI3 returns the handle to a new GUI3 or the handle to
%      the existing singleton*.
%
%      GUI3('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in GUI3.M with the given input arguments.
%
%      GUI3('Property','Value',...) creates a new GUI3 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before gui3_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to gui3_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help gui3

% Last Modified by GUIDE v2.5 25-May-2019 00:58:29

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @gui3_OpeningFcn, ...
                   'gui_OutputFcn',  @gui3_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before gui3 is made visible.
function gui3_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to gui3 (see VARARGIN)
set ( gcf, 'Color', [.9 .9 .9] )
% Choose default command line output for gui3
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes gui3 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = gui3_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
axes(handles.axes1)
% plot(sin(0:0.01:10));
% title('Sine')
fs=44100; %Sampling Frequency
[voice,fs]=audioread('last.wav');
dft_voice=abs(fft(voice)); %Fourier Trransform of Voice Signal
 plot(dft_voice);%title('Voice Signal'); %Frequency Spectrum of voice signal
 title('Original Signal')
%  xlim([-5 5])
% ylim([0 3500])
sound(voice,fs);

% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
axes(handles.axes2)
% plot(cos(0:0.01:10));
% title('Sine')
fs=44100; %Sampling Frequency
[voice,fs]=audioread('last.wav');
noisy=awgn(voice,10); %Adding Guassian Noise to the Signal
dft_noisy=abs(fft(noisy)); %Fourier Trransform of noisy Signal
plot(dft_noisy);%title('Noisy Signal');%Frequency Spectrum of noisy signal
title('Noisy Signal')
sound(noisy,fs);
% sound(y1,fs); %LowPass Filtered Sound
% sound(y2,fs);%BandPass Filtered Sound

% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
axes(handles.axes3)
fs=44100; %Sampling Frequency
[voice,fs]=audioread('last.wav');
noisy=awgn(voice,10);
y1=filter(lowpass,noisy);
dft_y1=abs(fft(y1)); %Fourier Trransform of LowPass Filtered Signal
plot(dft_y1);title('LowPass Filtered Signal');%Frequency Spectrum of LowPass Filtered signal
 sound(y1,fs); %LowPass Filtered Sound
% sound(y2,fs);%BandPass Filtered Sound

% --- Executes on button press in pushbutton4.
function pushbutton4_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
axes(handles.axes4)
fs=44100; %Sampling Frequency
[voice,fs]=audioread('last.wav');
noisy=awgn(voice,10);
y2=filter(bandpass,noisy);
dft_y2=abs(fft(y2)); %Fourier Trransform of BandPass Filtered Signal
plot(dft_y2);title('BandPass Filtered Signal');%Frequency Spectrum of bandPass filtered signal
% sound(y1,fs); %LowPass Filtered Sound
 sound(y2,fs);%BandPass Filtered Sound


% --- Executes on button press in pushbutton5.
function pushbutton5_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
cla(handles.axes1, 'reset');
cla(handles.axes2, 'reset');
cla(handles.axes3, 'reset');
cla(handles.axes4, 'reset');


% --- Executes on button press in pushbutton6.
function pushbutton6_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close gui3