package com.tvhms.ui;

import java.awt.Color;
import java.awt.Component;

import javax.swing.JProgressBar;
import javax.swing.JTable;
import javax.swing.UIManager;
import javax.swing.border.Border;
import javax.swing.border.EmptyBorder;
import javax.swing.plaf.UIResource;
import javax.swing.table.TableCellRenderer;

public class ProgressBarRenderer extends JProgressBar implements TableCellRenderer, UIResource {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	
	/**
	 * 
	 */
    private static final Border noFocusBorder = new EmptyBorder(1, 1, 1, 1);
	
    
    /**
     * 
     */
	public ProgressBarRenderer() {
		setMinimum(0);
		setMaximum(100);
		setStringPainted(true);
		setValue(0);
	}
	
	
	
	@Override
	public Component getTableCellRendererComponent(JTable table, Object value,
			boolean isSelected, boolean hasFocus, int row, int column) {
		// TODO Auto-generated method stub
		
        if (isSelected) {
            setForeground(Color.blue);
            setBackground(table.getSelectionBackground());
        }
        else {
            setForeground(Color.blue);
            setBackground(table.getBackground());
        }
        
        PrgValue prgValue = (PrgValue)value;
        setValue(prgValue.percent());
        setString(prgValue.toString());
        
        if (hasFocus) {
            setBorder(UIManager.getBorder("Table.focusCellHighlightBorder"));
        } else {
            setBorder(noFocusBorder);
        }

        return this;
	}

}
