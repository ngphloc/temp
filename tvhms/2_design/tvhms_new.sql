/*
Created		6/6/2012
Modified		9/28/2012
Project		
Model		
Company		
Author		
Version		
Database		mySQL 5 
*/


drop table IF EXISTS ServiceType;
drop table IF EXISTS Shift;
drop table IF EXISTS Depreciate;
drop table IF EXISTS Expense;
drop table IF EXISTS ExpenseType;
drop table IF EXISTS Voucher;
drop table IF EXISTS Provider;
drop table IF EXISTS Imexport;
drop table IF EXISTS Account;
drop table IF EXISTS CustomerExtras;
drop table IF EXISTS ServiceExtras;
drop table IF EXISTS Config;
drop table IF EXISTS Service;
drop table IF EXISTS Reserve;
drop table IF EXISTS Customer;
drop table IF EXISTS Room;
drop table IF EXISTS RoomType;


Create table RoomType (
	RoomTypeName Varchar(20) NOT NULL,
	Price Float NOT NULL COMMENT 'day, hours (karaoke)',
	Description Varchar(256),
 Primary Key (RoomTypeName)) ENGINE = MyISAM
COMMENT = 'Live, steam bath, karaoke ...';

Create table Room (
	RoomName Varchar(20) NOT NULL,
	RoomTypeName Varchar(20) NOT NULL,
	RoomFloor Int,
	UNIQUE (RoomName),
 Primary Key (RoomName)) ENGINE = MyISAM;

Create table Customer (
	CustomerId Int NOT NULL AUTO_INCREMENT,
	FullName Varchar(50),
	PersonalId Varchar(20),
	VehicleNumber Varchar(20),
 Primary Key (CustomerId)) ENGINE = MyISAM;

Create table Reserve (
	ReserveId Int NOT NULL AUTO_INCREMENT,
	RoomName Varchar(20) NOT NULL,
	CustomerId Int NOT NULL,
	Status Int NOT NULL COMMENT '0: Live, 1: Deposit, 2: Reservation (phone), 3: Paid',
	BeginDate Datetime NOT NULL,
	LiveType Int DEFAULT 0 COMMENT '0: ngay 1: gio',
	TotalDays Int DEFAULT 0,
	LivedDays Int,
	TotalPayment Float,
	Discount Float,
	Paid Float,
	TotalPersons Int DEFAULT 1,
	Children Int DEFAULT 0,
	Adult Int DEFAULT 0,
	ModifyDate Datetime,
	AccountId Varchar(20),
 Primary Key (ReserveId)) ENGINE = MyISAM;

Create table Service (
	ServiceName Varchar(50) NOT NULL,
	ServiceTypeName Varchar(256) NOT NULL,
	Unit Varchar(20),
	UnitPrice Float DEFAULT 0,
	TotalQuantity Int DEFAULT 0,
	TotalPrice Float DEFAULT 0,
	IsEquipment Bool,
	RemainingPrice Float DEFAULT 0,
	DepreciateRatio Bool,
	Description Varchar(256),
 Primary Key (ServiceName)) ENGINE = MyISAM;

Create table Config (
	ConfigAttribute Varchar(20) NOT NULL,
	ConfigValue Varchar(20) NOT NULL,
 Primary Key (ConfigAttribute)) ENGINE = MyISAM;

Create table ServiceExtras (
	ServiceExtrasId Int NOT NULL AUTO_INCREMENT,
	ServiceName Varchar(50) NOT NULL,
	ReserveId Int,
	Quantity Int NOT NULL,
	TotalPrice Float NOT NULL,
	IsCompensated Bool COMMENT 'Note that customer compensation is considered as service provide',
	Description Varchar(256),
	CustomerId Int COMMENT 'Some situations, customers do not reserve room but require services such as steam bath',
	ExtrasDate Datetime COMMENT 'Some situations, customers do not reserve room but require services such as steam bath',
 Primary Key (ServiceExtrasId,ServiceName)) ENGINE = MyISAM;

Create table CustomerExtras (
	ReserveId Int NOT NULL,
	CustomerId Int NOT NULL,
	BeginDate Datetime,
 Primary Key (ReserveId,CustomerId)) ENGINE = MyISAM;

Create table Account (
	AccountId Varchar(20) NOT NULL,
	AccountPassword Varchar(256) NOT NULL,
	FullName Varchar(50) NOT NULL,
	AccountRight Int COMMENT '1: staff, 3: manager',
	UNIQUE (AccountId),
	UNIQUE (AccountPassword),
 Primary Key (AccountId)) ENGINE = MyISAM;

Create table Imexport (
	ImexportId Int NOT NULL AUTO_INCREMENT,
	ServiceName Varchar(50) NOT NULL,
	ImexDate Datetime NOT NULL,
	Quantity Int NOT NULL,
	ImOrEx Bool NOT NULL,
	EnterPerson Varchar(50),
	ProviderName Varchar(256),
	AtStore Varchar(50),
	Description Varchar(256),
 Primary Key (ImexportId)) ENGINE = MyISAM;

Create table Provider (
	ProviderName Varchar(256) NOT NULL,
	TaxCode Varchar(20),
	Address Varchar(256),
	Phone Varchar(50),
	Fax Varchar(20),
	Website Varchar(256),
	Industry Varchar(50),
 Primary Key (ProviderName)) ENGINE = MyISAM;

Create table Voucher (
	CustomerId Int NOT NULL,
	VoucherTime Int NOT NULL,
	VoucherCode Varchar(20),
	IsExpired Bool NOT NULL,
	IsProcessed Bool NOT NULL,
	BeginDate Datetime,
	EndDate Datetime,
	Discount Float DEFAULT 0,
 Primary Key (CustomerId,VoucherTime)) ENGINE = MyISAM;

Create table ExpenseType (
	ExpenseTypeName Varchar(256) NOT NULL,
	Description Varchar(256),
 Primary Key (ExpenseTypeName)) ENGINE = MyISAM
COMMENT = 'Buy service, buy equipment, equipment depreciation, equipment decay, electric, water, compensate...';

Create table Expense (
	ExpenseId Int NOT NULL AUTO_INCREMENT,
	ImexportId Int NOT NULL,
	ExpenseDate Datetime NOT NULL,
	ExpenseTypeName Varchar(256) NOT NULL,
	ExpenseMoney Float DEFAULT 0,
	DepreciateId Int,
 Primary Key (ExpenseId)) ENGINE = MyISAM;

Create table Depreciate (
	DepreciateId Int NOT NULL AUTO_INCREMENT,
	DepreciateDate Datetime NOT NULL,
	ServiceName Varchar(50) NOT NULL,
	DepreciateExpense Float NOT NULL DEFAULT 0,
 Primary Key (DepreciateId)) ENGINE = MyISAM;

Create table Shift (
	AccountId Varchar(20) NOT NULL,
	BeginTime Time NOT NULL,
	EndTime Time NOT NULL,
 Primary Key (AccountId,BeginTime,EndTime)) ENGINE = MyISAM;

Create table ServiceType (
	ServiceTypeName Varchar(256) NOT NULL,
	Description Varchar(256),
 Primary Key (ServiceTypeName)) ENGINE = MyISAM
COMMENT = 'Beverage, food, laundry, equipment...';


