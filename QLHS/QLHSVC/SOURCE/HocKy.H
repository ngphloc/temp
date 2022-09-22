// HocKy.H : Declaration of the CHocKy class

#ifndef __HOCKY_H_
#define __HOCKY_H_

class CHocKyAccessor
{
public:
	LONG m_MaHK;
	TCHAR m_TenHK[51];
	TCHAR m_GhiChu[256];

BEGIN_COLUMN_MAP(CHocKyAccessor)
	COLUMN_ENTRY(1, m_MaHK)
	COLUMN_ENTRY(2, m_TenHK)
	COLUMN_ENTRY(3, m_GhiChu)
END_COLUMN_MAP()

DEFINE_COMMAND(CHocKyAccessor, _T(" \
	SELECT \
		MaHK, \
		TenHK, \
		GhiChu  \
		FROM HOCKY"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

class CHocKy : public CCommand<CAccessor<CHocKyAccessor> >
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

		return CCommand<CAccessor<CHocKyAccessor> >::Open(m_session, NULL, &propset);
	}
	CSession	m_session;
};

#endif // __HOCKY_H_
