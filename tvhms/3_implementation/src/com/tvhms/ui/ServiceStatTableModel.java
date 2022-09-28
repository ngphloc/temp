package com.tvhms.ui;

import java.util.Date;
import java.util.List;
import java.util.Vector;

import com.tvhms.entity.Entity;
import com.tvhms.entity.Service;
import com.tvhms.entity.ServiceStat;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class ServiceStatTableModel extends SortableTableModel {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	
	/**
	 * 
	 */
	public ServiceStatTableModel() {
		super();
	}
	
	
	
	/**
	 * 
	 * @return
	 */
	private Vector<String> createColumns() {
		Vector<String> columns = new Vector<>();
		
		columns.add("No");
		columns.add("Service");
		columns.add("Type");
		columns.add("Price");
		columns.add("Unit");
		columns.add("Total money (VND)");
		columns.add("Description");
		
		return columns;
	}
	
	
	/**
	 * 
	 */
	@SuppressWarnings("unchecked")
	public void update(Date startDate, Date endDate) {
		Vector<String> columns = createColumns();
		
		Vector<Vector<Object>> data = new Vector<Vector<Object>>();
		List<Service> serviceList = (List<Service>) Entity.load("from Service");
		for (int i = 0; i < serviceList.size(); i++) {
			Service service = serviceList.get(i);
			
			Vector<Object> row = new Vector<>();
			
			row.add(i + 1);
			row.add(service.getServiceName());
			row.add(service.getServiceType());
			row.add(service.getPrice());
			row.add(service.getUnit());
			
			ServiceStat stat = service.queryServiceStat(startDate, endDate);
			row.add(stat.TotalMoney);
			
			row.add(service.getDescription());
			
			data.add(row);
		}
		
		setDataVector(data, columns);
	}
	
	
	
	/**
	 * 
	 * @param row
	 * @return
	 */
	public Service getService(int row) {
		String serviceName = (String)getValueAt(row, 1);
		return (Service)Entity.load(Service.class, serviceName);
		
	}
	
	
	@Override
	public boolean isCellEditable(int row, int column) {
		// TODO Auto-generated method stub
		return false;
	}


	@Override
	public boolean isSortable(int column) {
		// TODO Auto-generated method stub
		return true;
	}
	
	
}
