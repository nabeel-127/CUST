function varargout = tdplot1(varargin)
% TDPLOT1 MATLAB code for tdplot1.fig
%      TDPLOT1, by itself, creates a new TDPLOT1 or raises the existing
%      singleton*.
%
%      H = TDPLOT1 returns the handle to a new TDPLOT1 or the handle to
%      the existing singleton*.
%
%      TDPLOT1('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in TDPLOT1.M with the given input arguments.
%
%      TDPLOT1('Property','Value',...) creates a new TDPLOT1 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before tdplot1_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to tdplot1_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help tdplot1

% Last Modified by GUIDE v2.5 28-May-2019 23:08:47

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @tdplot1_OpeningFcn, ...
                   'gui_OutputFcn',  @tdplot1_OutputFcn, ...
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


% --- Executes just before tdplot1 is made visible.
function tdplot1_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to tdplot1 (see VARARGIN)
set ( gcf, 'Color', [.5 .6 .9] )
% Choose default command line output for tdplot1
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes tdplot1 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = tdplot1_OutputFcn(hObject, eventdata, handles) 
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
plot(voice);
sound(voice,fs);          %for sound

% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
axes(handles.axes2)
% plot(sin(0:0.01:10));
% title('Sine')
fs=44100; %Sampling Frequency
[voice,fs]=audioread('last.wav');
noisy=awgn(voice,10);
plot(noisy);
sound(noisy,fs);


% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
axes(handles.axes3)
% plot(sin(0:0.01:10));
% title('Sine')
fs=44100; %Sampling Frequency
[voice,fs]=audioread('last.wav');
noisy=awgn(voice,10);
y1=filter(lowpass,noisy);
plot(y1);
sound(y1,fs);

% --- Executes on button press in pushbutton4.
function pushbutton4_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
axes(handles.axes4)
% plot(sin(0:0.01:10));
% title('Sine')
fs=44100; %Sampling Frequency
[voice,fs]=audioread('last.wav');
noisy=awgn(voice,10);
y2=filter(bandpass,noisy);
plot(y2);
sound(y2,fs);



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
close tdplot1
