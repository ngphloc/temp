package com.tvhms.ui;

import java.awt.Color;
import java.awt.Component;

import javax.swing.JTable;
import javax.swing.UIManager;
import javax.swing.table.DefaultTableCellRenderer;

import com.tvhms.entity.Reserve.Status;

/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public class StatusRenderer extends DefaultTableCellRenderer.UIResource {
	
	/**
	 * 
	 */
	private Color LIVING_COLOR = Color.red.brighter();
	
	
	/**
	 * 
	 */
	private Color DEPOSIT_COLOR = Color.orange.brighter();
	
	/**
	 * 
	 */
	private Color RESERVE_COLOR = Color.PINK.brighter();
	
	/**
	 * 
	 */
	private Color AVAILABLE_COLOR = Color.white.brighter();
	
	
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;


	/**
	 * 
	 */
    public StatusRenderer() {
        super();
    }
    
    
    @Override
    public Component getTableCellRendererComponent(JTable table, Object value,
            boolean isSelected, boolean hasFocus, int row, int column) {
    	super.getTableCellRendererComponent(
    			table, value, isSelected, hasFocus, row, column);
    	
    	Color bgrColor = Color.white;
    	Status status = (Status)value;
    	
    	switch (status) {
    	case living:
    		bgrColor = LIVING_COLOR;
    		break;
    	case deposit:
    		bgrColor = DEPOSIT_COLOR;
    		break;
    	case reserve:
    		bgrColor = RESERVE_COLOR;
    		break;
    	case available:
    		bgrColor = AVAILABLE_COLOR;
    		break;
    	}
    	
    	
    	if (isSelected)
    		bgrColor = bgrColor.darker();
		setBackground(bgrColor);
		setForeground(Color.black);
		
    	if (hasFocus) {
    		setBorder(UIManager.getBorder("Table.focusCellHighlightBorder"));
    	} 
    	else {
    		setBorder(noFocusBorder);
    	}

    	return this;
    }
}
