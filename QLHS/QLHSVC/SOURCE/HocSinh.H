// HocSinh.H : Declaration of the CHocSinh class

#ifndef __HOCSINH_H_
#define __HOCSINH_H_

class CHocSinhAccessor
{
public:
	TCHAR m_MaHS[51];
	TCHAR m_HoTenHS[51];
	VARIANT_BOOL m_Nam;
	DBTIMESTAMP m_NgaySinhHS;
	TCHAR m_DiaChiHS[256];
	ISequentialStream* m_HinhAnhHS;
	LONG m_DienHS;
	LONG m_SoNgayVang;

BEGIN_COLUMN_MAP(CHocSinhAccessor)
	COLUMN_ENTRY(1, m_MaHS)
	COLUMN_ENTRY(2, m_HoTenHS)
	COLUMN_ENTRY_TYPE(3, DBTYPE_BOOL, m_Nam)
	COLUMN_ENTRY(4, m_NgaySinhHS)
	COLUMN_ENTRY(5, m_DiaChiHS)
	BLOB_ENTRY(6, IID_ISequentialStream, STGM_READ, m_HinhAnhHS)
	COLUMN_ENTRY(7, m_DienHS)
	COLUMN_ENTRY(8, m_SoNgayVang)
END_COLUMN_MAP()

DEFINE_COMMAND(CHocSinhAccessor, _T(" \
	SELECT \
		MaHS, \
		HoTenHS, \
		Nam, \
		NgaySinhHS, \
		DiaChiHS, \
		HinhAnhHS, \
		DienHS, \
		SoNgayVang  \
		FROM HOCSINH"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

class CHocSinh : public CCommand<CAccessor<CHocSinhAccessor> >
{
public:
	HRESULT Open()
	{
		HRESULT		hr;

		hr = OpenDataSource();
		if (FAILED(hr))
			return hr;

		return OpenRowset();
	}
	HRESULT OpenDataSource()
	{
		HRESULT		hr;
		CDataSource db;
		CDBPropSet	dbinit(DBPROPSET_DBINIT);

		dbinit.AddProperty(DBPROP_AUTH_PASSWORD, OLESTR("29081979"));
		dbinit.AddProperty(DBPROP_AUTH_PERSIST_SENSITIVE_AUTHINFO, false);
		dbinit.AddProperty(DBPROP_AUTH_USERID, OLESTR("sa"));
		dbinit.AddProperty(DBPROP_INIT_CATALOG, OLESTR("QLHS"));
		dbinit.AddProperty(DBPROP_INIT_DATASOURCE, OLESTR("9700454"));
		dbinit.AddProperty(DBPROP_INIT_LCID, (long)1033);
		dbinit.AddProperty(DBPROP_INIT_PROMPT, (short)4);
		hr = db.Open(_T("SQLOLEDB.1"), &dbinit);
		if (FAILED(hr))
			return hr;

		m_session.Close();
		return m_session.Open(db);
	}
	HRESULT OpenRowset()
	{
		// Set properties for open
		CDBPropSet	propset(DBPROPSET_ROWSET);
		propset.AddProperty(DBPROP_IRowsetChange, true);
		propset.AddProperty(DBPROP_UPDATABILITY, DBPROPVAL_UP_CHANGE | DBPROPVAL_UP_INSERT | DBPROPVAL_UP_DELETE);
		propset.AddProperty(DBPROP_CANSCROLLBACKWARDS,true);
		propset.AddProperty(DBPROP_REMOVEDELETED,true);

		return CCommand<CAccessor<CHocSinhAccessor> >::Open(m_session, NULL, &propset);
	}
	CSession	m_session;
};

#endif // __HOCSINH_H_
