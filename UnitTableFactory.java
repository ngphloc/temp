package net.hudup.core.data.factory;

import java.awt.Component;
import java.sql.SQLException;
import java.util.Map;

import javax.swing.event.EventListenerList;

import org.apache.log4j.Logger;

import net.hudup.core.data.ParamSql;
import net.hudup.core.data.Provider;
import net.hudup.core.data.ui.UnitTable;
import quick.dbtable.Column;
import quick.dbtable.DBTable;
import quick.dbtable.DBTableEventListener;
import quick.dbtable.DatabaseChangeListener;


/**
 * Factory class to create a table for showing data in unit.
 * 
 * @author Loc Nguyen
 * @version 10.0
 *
 */
public class UnitTableFactory {

	
	/**
	 * Main class to create a table for showing data in unit.
	 * @return {@link UnitTable} created.
	 */
	public static UnitTable create() {
		return new UnitTableImpl();
	}
	
	
}


/**
 * This is the implementation of {@link UnitTable} for database.
 * 
 * @author Loc Nguyen
 * @version 10.0
 *
 */
class UnitTableImpl extends DBTable implements UnitTable {

	
	/**
	 * Serial version UID for serializable class. 
	 */
	private static final long serialVersionUID = 1L;

	
	/**
	 * Logger of this class.
	 */
	protected final static Logger logger = Logger.getLogger(UnitTable.class);

	
	/**
	 * Holding a list of event listeners.
	 * 
	 */
    protected EventListenerList listenerList = new EventListenerList();
    
    
	/**
	 * Default constructor.
	 */
	public UnitTableImpl() {
		super();
		// TODO Auto-generated constructor stub
		setEditable(true);
		createControlPanel();
	}


	/**
	 * Getting this table.
	 * @return this table.
	 */
	private UnitTable getThis() {
		return this;
	}
	
	
	@Override
	public void update(Provider provider, String unit) {
		if (provider == null)
			return;
		
		if (! (provider.getAssoc() instanceof DbProviderAssoc) ) {
			logger.error("UnitTable currently not support none-database provider");
			return;
		}
		
		DbProviderAssoc dbAssoc = (DbProviderAssoc) provider.getAssoc();
		setConnection(dbAssoc.getConnection());

		String select = dbAssoc.genSelectSql(unit);
		setSelectSql(select);
		
		ParamSql insert = dbAssoc.genInsertSql(unit);
		clearAllInsertSql();
		addInsertSql(insert.getSql(), insert.getIndexText(true));
		
		ParamSql update = dbAssoc.genUpdateSql(unit);
		clearAllUpdateSql();
		addUpdateSql(update.getSql(), update.getIndexText(true));
		
		ParamSql delete = dbAssoc.genDeleteSql(unit);
		clearAllDeleteSql();
		addDeleteSql(delete.getSql(), delete.getIndexText(true));
		
		try {
			refresh();
			
			Map<Integer, String> boundSql = dbAssoc.genAttributeBoundSql(unit);
			
			if (boundSql.size() > 0) {
				int n = getColumnCount();
				for (int i = 0; i < n; i++) {
					if (boundSql.containsKey(i)) {
						Column column = getColumn(i);
						String sql = boundSql.get(i);
						column.setBoundSql(sql);
					}
				}
			}
		} 
		catch (Throwable e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		addDBTableEventListener(new DBTableEventListener() {

			@Override
			public void afterRowSelectionChange(int fromRow, int toRow) {
				// TODO Auto-generated method stub
				super.afterRowSelectionChange(fromRow, toRow);
				fireSelectionChangedEvent(new SelectionChangedEvent(getThis()));
			}
			
		});
		
		addDatabaseChangeListener(new DatabaseChangeListener() {

			@Override
			public void afterDelete(int row) {
				// TODO Auto-generated method stub
				super.afterDelete(row);
				fireSelectionChangedEvent(new SelectionChangedEvent(getThis()));
			}

			@Override
			public void afterInsert(int row) {
				// TODO Auto-generated method stub
				super.afterInsert(row);
				fireSelectionChangedEvent(new SelectionChangedEvent(getThis()));
			}

			@Override
			public void afterUpdate(int row) {
				// TODO Auto-generated method stub
				super.afterUpdate(row);
				fireSelectionChangedEvent(new SelectionChangedEvent(getThis()));
			}
			
		});

		
		setEditable(true);
	}
	
	
	@Override
	public void clear() {
		clearAllDeleteSql();
		clearAllInsertSql();
		clearAllUpdateSql();
		removeAllRows();
		
		try {
			close();
		} 
		catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}


	@Override
	public void refresh() {
		// TODO Auto-generated method stub
		try {
			super.refresh();
		} 
		catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}


	@Override
	public Component getComponent() {
		// TODO Auto-generated method stub
		return this;
	}
	
	
	@Override
	public void addSelectionChangedListener(SelectionChangedListener listener) {
		synchronized (listenerList) {
			listenerList.add(SelectionChangedListener.class, listener);
		}
    }

    
	@Override
    public void removeSelectionChangedListener(SelectionChangedListener listener) {
		synchronized (listenerList) {
			listenerList.remove(SelectionChangedListener.class, listener);
		}
    }
	
    
    /**
     * Return array of selection changed listeners.
     * @return array of selection changed listeners.
     */
    protected SelectionChangedListener[] getSelectionChangedListeners() {
		synchronized (listenerList) {
			return listenerList.getListeners(SelectionChangedListener.class);
		}
    }

    
    /**
     * Firing (issuing) an event from this table to all selection changed listeners. 
     * @param evt selection changed event.
     */
    protected void fireSelectionChangedEvent(SelectionChangedEvent evt) {
    	
    	SelectionChangedListener[] listeners = getSelectionChangedListeners();
		
		for (SelectionChangedListener listener : listeners) {
			try {
				listener.respond(evt);
			}
			catch (Throwable e) {
				e.printStackTrace();
			}
		}
	
    }


}
