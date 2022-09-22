// KhoiLop.H : Declaration of the CKhoiLop class

#ifndef __KHOILOP_H_
#define __KHOILOP_H_

class CKhoiLopAccessor
{
public:
	LONG m_MaKL;
	TCHAR m_TenKL[51];

BEGIN_COLUMN_MAP(CKhoiLopAccessor)
	COLUMN_ENTRY(1, m_MaKL)
	COLUMN_ENTRY(2, m_TenKL)
END_COLUMN_MAP()

DEFINE_COMMAND(CKhoiLopAccessor, _T(" \
	SELECT \
		MaKL, \
		TenKL  \
		FROM KHOILOP"))

	// You may wish to call this function if you are inserting a record and wish to
	// initialize all the fields, if you are not going to explicitly set all of them.
	void ClearRecord()
	{
		memset(this, 0, sizeof(*this));
	}
};

class CKhoiLop : public CCommand<CAccessor<CKhoiLopAccessor> >
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

		return CCommand<CAccessor<CKhoiLopAccessor> >::Open(m_session, NULL, &propset);
	}
	CSession	m_session;
};

#endif // __KHOILOP_H_
