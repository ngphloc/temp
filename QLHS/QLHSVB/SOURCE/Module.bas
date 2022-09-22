Attribute VB_Name = "Module"
Option Explicit
Public DBPath As String
Public RPPath As String
Public MaXepLop As String
Public MaHS As String
Public MaLop As String
Public MaDay As String
Public MaGV As String
Public MaMH As String

Public Sub DiemTB(MaHocSinh As Long, NienKhoa As Long, ByRef DiemTBHKI As Single, ByRef DiemTBHKII As Single, ByRef DiemTBCN As Single)
    Dim LSQL As String
    Dim cSQL As String
    Dim wk As Workspace
    Dim Db As Database
    Dim rs As Recordset
    'Dim t1, t2 As Single
    'Dim SoMH As Integer
    'Dim MaMH(10) As Integer
    Dim i As Integer
    Dim total As Single
    
    LSQL = "SELECT HocSinh.MaHS, Lop.NienKhoa, Hoc.MaHK, MonHoc.MaMH, "
    LSQL = LSQL & "MonHoc.Heso, Diem.HinhThucKT, Diem.Diem "
    LSQL = LSQL & "FROM ((((Hoc INNER JOIN XepLop ON Hoc.MaXepLop = XepLop.MaXepLop) "
    LSQL = LSQL & "INNER JOIN HocSinh ON XepLop.MaHS = HocSinh.MaHS) INNER JOIN Lop ON XepLop.MaLop =  "
    LSQL = LSQL & "Lop.MaLop) INNER JOIN MonHoc ON Hoc.MaMH = MonHoc.MaMH)  "
    LSQL = LSQL & " INNER JOIN Diem ON Hoc.MaHoc = Diem.MaHoc "
    LSQL = LSQL & " WHERE  HocSinh.MaHS =  " & Str(MaHocSinh)
    LSQL = LSQL & " AND Lop.NienKhoa =  " & Str(NienKhoa)
    cSQL = LSQL & " AND Hoc.MaHK =  1"
    
    Set wk = DBEngine.CreateWorkspace("", "Admin", "", dbUseJet)
    Set Db = wk.OpenDatabase(DBPath)
    Set rs = Db.OpenRecordset(cSQL)
    
    Debug.Print rs.RecordCount
    DiemTBHKI = 0
    DiemTBHKII = 0
    DiemTBCN = 0
    total = 0
    't1 = 0
    't2 = 0
    'SoMH = 0
        
    If rs.RecordCount > 0 Then
        Do While (Not rs.EOF)
            total = total + rs.Fields(6).Value
            rs.MoveNext
        Loop
        DiemTBHKI = total / rs.RecordCount
        'MaMH(SoMH) = rs.Fields(3)
        'SoMH = SoMH + 1
        'If (Not rs.EOF) Then rs.MoveNext
        'Do While (Not rs.EOF)
            'If (MaMH(SoMH - 1) <> rs.Fields(3)) Then
                'MaMH(SoMH) = rs.Fields(3)
                'SoMH = SoMH + 1
            'End If
            'rs.MoveNext
        'Loop
        'rs.Close
        
        'If (SoMH > 0) Then
            'For i = 0 To SoMH - 1
                'cSQL = cSQL & " AND MonHoc.MaMH = 10" ' & Str(MaMH(i))
                'Set rs = db.OpenRecordset(cSQL)
                't1 = 0
                't2 = 0
                'Do While (Not rs.EOF)
                    'If (rs.Fields(5).Value = 0) Or (rs.Fields(5).Value = 1) Then
                        't1 = t1 + rs.Fields(6).Value
                    'End If
                    'If rs.Fields(5).Value = 2 Then
                        't1 = t1 + 2 * rs.Fields(6)
                    'End If
                'Loop
                'rs.MoveFirst
                'rs.Close
            'Next i
        'End If
    End If
    
    total = 0
    cSQL = LSQL & " AND  Hoc.MaHK = 2 "
    Set rs = Db.OpenRecordset(cSQL)
    If rs.RecordCount > 0 Then
        Do While (Not rs.EOF)
            total = total + rs.Fields(6).Value
            rs.MoveNext
        Loop
        DiemTBHKII = total / rs.RecordCount
    End If
    
    DiemTBCN = (DiemTBHKI + DiemTBHKII * 2) / 3
    rs.Close
    Db.Close
    wk.Close
End Sub
