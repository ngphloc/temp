package com.tvhms.entity;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

import org.hibernate.Session;

import com.tvhms.Service;


/**
 * 
 * @author Administrator2
 * @version 1.0
 *
 */
public abstract class Entity {

	
	/**
	 * 
	 * @return
	 */
	public Serializable save() {
		try {
			Session session = Service.getSessionFactory().openSession();
			session.beginTransaction();
			Serializable id = session.save(this);
			session.getTransaction().commit();
			session.close();
			
			return id;
		}
		catch (Exception e) {
			e.printStackTrace();
			return null;
		}
	}
	
	
	/**
	 * 
	 * @return
	 */
	public boolean update() {
		try {
			Session session = Service.getSessionFactory().openSession();
			session.beginTransaction();
			session.update(this);
			session.getTransaction().commit();
			session.close();
			
			return true;
		}
		catch (Exception e) {
			e.printStackTrace();
			return false;
		}
		
	}
	
	
	
	
	/**
	 * 
	 * @param query
	 * @return
	 */
	public static List<?> load(String query) {
		try {
			Session session = Service.getSessionFactory().openSession();
			
			session.beginTransaction();
			List<?> result = session.createQuery(query).list();
			session.close();
			
			return result;
		}
		catch (Exception e) {
			e.printStackTrace();
			
			return new ArrayList<>();
		}
	}
	
	
	
	/**
	 * 
	 * @param query
	 * @return
	 */
	public static EntityListSession loadExt(String query) {
		Session session = null;
		try {
			session = Service.getSessionFactory().openSession();
			
			session.beginTransaction();
			List<?> entityList = session.createQuery(query).list();
			
			return new EntityListSession(entityList, session);
		}
		catch (Exception e) {
			e.printStackTrace();
			if (session != null)
				session.close();
			return null;
		}

	}

	
	
	/**
	 * 
	 * @return
	 */
	public static Entity load(Class<? extends Entity> entityClass, Serializable id) {
		try {
			Session session = Service.getSessionFactory().openSession();
			
			session.beginTransaction();
			Entity entity = (Entity) session.get(entityClass, id);
			session.close();
			
			return entity;
		}
		catch (Exception e) {
			e.printStackTrace();
			
			return null;
		}
	}
	
	
	/**
	 * 
	 * @param entityClass
	 * @param id
	 * @return
	 */
	public static EntitySession loadExt(Class<? extends Entity> entityClass, Serializable id) {
		Session session = null;
		try {
			session = Service.getSessionFactory().openSession();
			
			session.beginTransaction();
			Entity entity = (Entity) session.get(entityClass, id);
			
			return new EntitySession(entity, session);
		}
		catch (Exception e) {
			e.printStackTrace();
			if (session != null)
				session.close();
			return null;
		}
	}

	
	/**
	 * 
	 * @author Administrator2
	 * @version 1.0
	 *
	 */
	public static class EntitySession {
		
		/**
		 * 
		 */
		protected Entity entity = null;
		
		
		/**
		 * 
		 */
		protected Session session = null;
		
		
		/**
		 * 
		 * @param entity
		 * @param session
		 */
		public EntitySession(Entity entity, Session session) {
			this.entity = entity;
			this.session = session;
		}
		
		
		/**
		 * 
		 * @return
		 */
		public Entity getEntity() {
			return entity;
		}
		
		
		/**
		 * 
		 * @return
		 */
		public Session getSession() {
			return session;
		}
		
		
		/**
		 * 
		 */
		public void close() {
			if (session != null)
				session.close();
			
			session = null;
			entity = null;
		}
		
	}
	
	
	public static class EntityListSession {
		
		/**
		 * 
		 */
		protected List<?> entityList = null;
		
		
		/**
		 * 
		 */
		protected Session session = null;
		
		
		/**
		 * 
		 * @param entityList
		 * @param session
		 */
		public EntityListSession(List<?> entityList, Session session) {
			this.entityList = entityList;
			this.session = session;
		}
		
		
		/**
		 * 
		 * @return
		 */
		public List<?> getEntityList() {
			return entityList;
		}
		
		
		/**
		 * 
		 * @return
		 */
		public Session getSession() {
			return session;
		}
		
		
		/**
		 * 
		 */
		public void close() {
			if (session != null)
				session.close();
			session = null;
			
			if (entityList != null)
				entityList.clear();
			entityList = null;
		}
		
	}

	
	/**
	 * 
	 * @return
	 */
	public boolean delete() {
		try {
			Session session = Service.getSessionFactory().openSession();
			
			session.beginTransaction();
			session.delete(this);
			session.getTransaction().commit();
			session.close();
			
			return true;
		}
		catch (Exception e) {
			e.printStackTrace();
			
			return false;
		}
	}
	
	
	/**
	 * 
	 * @return
	 */
	public abstract Serializable queryId();
	
	
	
}
