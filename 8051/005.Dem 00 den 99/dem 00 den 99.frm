VERSION 5.00
Object = "{648A5603-2C6E-101B-82B6-000000000014}#1.1#0"; "MSCOMM32.OCX"
Begin VB.Form Form1 
   Caption         =   "Dem 00 den 99"
   ClientHeight    =   3240
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   5400
   LinkTopic       =   "Form1"
   ScaleHeight     =   3240
   ScaleWidth      =   5400
   StartUpPosition =   3  'Windows Default
   Begin MSCommLib.MSComm MSComm1 
      Left            =   4680
      Top             =   840
      _ExtentX        =   1005
      _ExtentY        =   1005
      _Version        =   393216
      DTREnable       =   -1  'True
   End
   Begin VB.CommandButton Command4 
      Caption         =   "Stop"
      CausesValidation=   0   'False
      Height          =   495
      Left            =   3360
      TabIndex        =   7
      Top             =   2160
      Width           =   1095
   End
   Begin VB.Frame Frame2 
      Caption         =   "Dem tu so x den 99"
      Height          =   975
      Left            =   360
      TabIndex        =   4
      Top             =   1920
      Width           =   4215
      Begin VB.CommandButton Command3 
         Caption         =   "Start"
         CausesValidation=   0   'False
         Height          =   495
         Left            =   1560
         TabIndex        =   6
         Top             =   240
         Width           =   1095
      End
      Begin VB.TextBox Text1 
         Height          =   375
         Left            =   240
         TabIndex        =   5
         Top             =   360
         Width           =   1095
      End
   End
   Begin VB.CommandButton Command2 
      Caption         =   "Stop"
      Height          =   495
      Left            =   2760
      TabIndex        =   3
      Top             =   960
      Width           =   1215
   End
   Begin VB.Frame Frame1 
      Caption         =   "Dem 00 den 99"
      Height          =   1095
      Left            =   240
      TabIndex        =   1
      Top             =   600
      Width           =   4335
      Begin VB.CommandButton Command1 
         Caption         =   "Start"
         Height          =   495
         Left            =   720
         TabIndex        =   2
         Top             =   360
         Width           =   1215
      End
   End
   Begin VB.Label Label1 
      Caption         =   "Dieu khien LED 7 thanh dem 00 den 99"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   13.5
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   240
      TabIndex        =   0
      Top             =   120
      Width           =   4935
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Command1_Click()
send ("s")
End Sub
Private Sub send(x As String)
If MSComm1.PortOpen = True Then
MSComm1.Output = x
End If
End Sub

Private Sub Command3_Click()
so = Val(Text1.Text)
send (Val(3))
End Sub

Private Sub Form_Load()
With MSComm1
.Settings = "9600,N,8,1"
.CommPort = 2
.SThreshold = 1
.RThreshold = 1
.InputLen = 1
.InputMode = 0
.PortOpen = True
End With
End Sub

