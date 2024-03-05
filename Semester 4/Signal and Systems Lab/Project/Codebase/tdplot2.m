function varargout = tdplot2(varargin)
% TDPLOT2 MATLAB code for tdplot2.fig
%      TDPLOT2, by itself, creates a new TDPLOT2 or raises the existing
%      singleton*.
%
%      H = TDPLOT2 returns the handle to a new TDPLOT2 or the handle to
%      the existing singleton*.
%
%      TDPLOT2('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in TDPLOT2.M with the given input arguments.
%
%      TDPLOT2('Property','Value',...) creates a new TDPLOT2 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before tdplot2_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to tdplot2_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help tdplot2

% Last Modified by GUIDE v2.5 28-May-2019 23:12:55

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @tdplot2_OpeningFcn, ...
                   'gui_OutputFcn',  @tdplot2_OutputFcn, ...
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


% --- Executes just before tdplot2 is made visible.
function tdplot2_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to tdplot2 (see VARARGIN)
set ( gcf, 'Color', [.7 .2 .8] )
% Choose default command line output for tdplot2
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes tdplot2 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = tdplot2_OutputFcn(hObject, eventdata, handles) 
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
noisy=awgn(voice,10);
plot(noisy);
sound(noisy,fs);

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
y1=filter(lowpass,noisy);
plot(y1);
sound(y1,fs);



% --- Executes on button press in pushbutton4.
function pushbutton4_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton4 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
cla(handles.axes1, 'reset');
cla(handles.axes2, 'reset');

% --- Executes on button press in pushbutton5.
function pushbutton5_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton5 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close tdplot2