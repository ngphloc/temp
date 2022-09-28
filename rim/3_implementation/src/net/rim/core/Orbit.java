package net.rim.core;

import java.util.ArrayList;
import java.util.List;


/**
 * @author Administrator2
 * @version 1.0
 * @created 04-Sep-2012 10:23:23 AM
 */
public class Orbit {
	
	/**
	 * 
	 */
	protected List<Location> locations = new ArrayList<Location>();


	/**
	 * 
	 */
	public Orbit() {

	}

	
	
	/**
	 * 
	 * @param location
	 */
	public void addLocation(Location location) {
		locations.add(location);
	}

	
	
	/**
	 * 
	 * @param locationIndex
	 */
	public Location getLocation(int locationIndex){
		return locations.get(locationIndex);
	}

	
	/**
	 * 
	 * @return
	 */
	public int getLocationCount(){
		return locations.size();
	}

	
	
	/**
	 * 
	 * @param locationIndex
	 */
	public void removeLocation(int locationIndex){
		locations.remove(locationIndex);
	}

	
	
}