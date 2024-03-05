function varargout = echo_effect(varargin)
% ECHO_EFFECT MATLAB code for echo_effect.fig
%      ECHO_EFFECT, by itself, creates a new ECHO_EFFECT or raises the existing
%      singleton*.
%
%      H = ECHO_EFFECT returns the handle to a new ECHO_EFFECT or the handle to
%      the existing singleton*.
%
%      ECHO_EFFECT('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in ECHO_EFFECT.M with the given input arguments.
%
%      ECHO_EFFECT('Property','Value',...) creates a new ECHO_EFFECT or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before echo_effect_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to echo_effect_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help echo_effect

% Last Modified by GUIDE v2.5 28-May-2019 23:24:43

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @echo_effect_OpeningFcn, ...
                   'gui_OutputFcn',  @echo_effect_OutputFcn, ...
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


% --- Executes just before echo_effect is made visible.
function echo_effect_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to echo_effect (see VARARGIN)
set ( gcf, 'Color', [.7 .6 .9] )
% Choose default command line output for echo_effect
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes echo_effect wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = echo_effect_OutputFcn(hObject, eventdata, handles) 
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
fs=44100
voice=audioread('last.wav')
plot(voice);
sound(voice,fs)





% --- Executes on button press in pushbutton2.
function pushbutton2_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
axes(handles.axes2)
fs=44100
voice=audioread('last.wav')
plot(voice);
sound(voice,fs)
mono=(voice(:,1)+voice(:,2))/2;
h1=[0.4 zeros(1,15000)];
h2=[0.3 zeros(1,15000)];
h3=[0.3 zeros(1,15000)];
h4=[0.2 zeros(1,15000)];
h=[h1 h2];
hh=[h h3];
hf=[hh h4];
echo=conv(mono,hf);
sound(echo,fs);
plot(echo);




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
close echo_effect