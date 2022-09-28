-- phpMyAdmin SQL Dump
-- version 3.4.5
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Sep 26, 2012 at 03:46 AM
-- Server version: 5.5.16
-- PHP Version: 5.3.8

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `tvhms`
--

-- --------------------------------------------------------

--
-- Table structure for table `account`
--

DROP TABLE IF EXISTS `account`;
CREATE TABLE IF NOT EXISTS `account` (
  `AccountId` varchar(20) COLLATE utf8_unicode_ci NOT NULL,
  `AccountPassword` varchar(256) COLLATE utf8_unicode_ci NOT NULL,
  `FullName` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `AccountRight` int(11) DEFAULT NULL COMMENT '1: staff, 3: manager',
  PRIMARY KEY (`AccountId`),
  UNIQUE KEY `AccountId` (`AccountId`),
  UNIQUE KEY `AccountPassword` (`AccountPassword`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `account`
--

INSERT INTO `account` (`AccountId`, `AccountPassword`, `FullName`, `AccountRight`) VALUES
('manager', '', 'Manager', 3),
('admin', '3335474112287-91-8967-119741474-12831-61', 'Administrator', 3),
('admin2', '-566688-23-61-11289-88-102-73125-124109-38-719', 'Admin2', 3);

-- --------------------------------------------------------

--
-- Table structure for table `config`
--

DROP TABLE IF EXISTS `config`;
CREATE TABLE IF NOT EXISTS `config` (
  `ConfigAttribute` varchar(20) COLLATE utf8_unicode_ci NOT NULL,
  `ConfigValue` varchar(20) COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`ConfigAttribute`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

-- --------------------------------------------------------

--
-- Table structure for table `customer`
--

DROP TABLE IF EXISTS `customer`;
CREATE TABLE IF NOT EXISTS `customer` (
  `CustomerId` int(11) NOT NULL AUTO_INCREMENT,
  `PersonalId` varchar(20) COLLATE utf8_unicode_ci DEFAULT NULL,
  `FullName` varchar(50) COLLATE utf8_unicode_ci DEFAULT NULL,
  `VehicleNumber` varchar(20) COLLATE utf8_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`CustomerId`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=77 ;

--
-- Dumping data for table `customer`
--

INSERT INTO `customer` (`CustomerId`, `PersonalId`, `FullName`, `VehicleNumber`) VALUES
(1, NULL, 'sfgsag', NULL),
(2, NULL, 'sfgsag', NULL),
(3, NULL, 'sfgsag', NULL),
(4, NULL, 'sfgsag', NULL),
(5, NULL, 'sfgsag', NULL),
(6, NULL, 'sfgsag', NULL),
(7, NULL, 'sfgsag', NULL),
(8, 'eetqwt23652356', 'rrrttttt', 'vsat3246352'),
(9, NULL, 'sfgsag', NULL),
(10, NULL, 'sfgsag', NULL),
(11, NULL, 'sfgsag', NULL),
(12, NULL, 'sfgsag', NULL),
(13, NULL, 'sfgsag', NULL),
(14, NULL, 'sfgsag', NULL),
(15, NULL, 'sfgsag', NULL),
(16, NULL, 'sfgsag', NULL),
(17, NULL, 'sfgsag', NULL),
(18, NULL, 'sfgsag', NULL),
(19, NULL, 'sfgsag', NULL),
(20, NULL, 'sfgsag', NULL),
(21, NULL, 'sfgsag', NULL),
(22, NULL, 'sfgsag', NULL),
(23, NULL, 'sfgsag', NULL),
(24, NULL, 'sfgsag', NULL),
(25, NULL, 'sfgsag', NULL),
(26, NULL, 'sfgsag', NULL),
(27, NULL, 'sfgsag', NULL),
(28, NULL, 'sfgsag', NULL),
(29, NULL, 'sfgsag', NULL),
(30, NULL, 'sfgsag', NULL),
(31, NULL, 'sfgsag', NULL),
(32, NULL, 'sfgsag', NULL),
(33, NULL, 'sfgsag', NULL),
(34, NULL, 'sfgsag', NULL),
(35, NULL, 'sfgsag', NULL),
(36, NULL, 'sfgsag', NULL),
(37, NULL, 'sfgsag', NULL),
(38, NULL, 'fgh', NULL),
(39, NULL, 'adfasdfa', NULL),
(40, NULL, 'adfasdfa', NULL),
(41, 'dsfgdsfh', 'customer', 'sdhdghd'),
(42, NULL, 'aaaaaaaaaaaa', NULL),
(43, NULL, 'bbbbbbbbbbbbbb', NULL),
(44, NULL, 'sfgsag', NULL),
(45, NULL, 'gdsfg', NULL),
(46, NULL, 'wwwwwwwwww', NULL),
(47, NULL, 'aaaaa', NULL),
(48, NULL, 'fgh', NULL),
(49, NULL, 'xxxxxxxxxxx', NULL),
(50, 'safgsafg', 'yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyrrreyr', 'asgasg'),
(51, NULL, 'gdsfg', NULL),
(52, NULL, 'dsgeg', NULL),
(53, NULL, 'dfhrej', NULL),
(54, NULL, 'wwwwwwwwww', NULL),
(55, NULL, 'aaaaaaa', NULL),
(56, NULL, 'dgdghds', NULL),
(57, NULL, 'fgdsgh', NULL),
(58, NULL, 'dfdsh', NULL),
(59, NULL, 'dfgdfsh', NULL),
(60, NULL, 'aaaaaaaaa', NULL),
(61, NULL, 'zzzzzzzzzzzzz', NULL),
(62, NULL, 'yyyyy', NULL),
(63, NULL, 'zzzz', NULL),
(64, NULL, 'yyyyy', NULL),
(65, NULL, 'fghfgh', NULL),
(66, NULL, 'kkkk', NULL),
(67, 'dfgdfs', 'dgdh', 'dfgdfs'),
(68, 'thjtrury', 'retyruryutjghj', 'thjtrury'),
(69, 'ruryu', 'rtuyryr', 'ruryu'),
(70, 'sfsd', 'qqqqqqqqqqqqqqqqqqqqqqq', 'sfsd'),
(71, 'sdfsg', 'z', 'sdfsg'),
(72, 'jkkjl', 'ggggggggggggggggggggg', 'jkkjl'),
(73, 'sdfsagsags', 'aslkgjhslgkshflgsdfhg', 'asgsag'),
(74, 'asfgdfshgpyti', 'adfsagsdfdsgb', 'zvasgf246dbh'),
(75, 'dsfgdsh', 'sdgfsdgdsfgh', 'dshds'),
(76, 'sdgsdf', 'sfgsfdg', 'dsfgh');

-- --------------------------------------------------------

--
-- Table structure for table `customerextras`
--

DROP TABLE IF EXISTS `customerextras`;
CREATE TABLE IF NOT EXISTS `customerextras` (
  `ReserveId` int(11) NOT NULL,
  `CustomerId` int(11) NOT NULL,
  `BeginDate` datetime DEFAULT NULL,
  PRIMARY KEY (`ReserveId`,`CustomerId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `customerextras`
--

INSERT INTO `customerextras` (`ReserveId`, `CustomerId`, `BeginDate`) VALUES
(164, 67, NULL),
(164, 41, NULL),
(164, 68, NULL),
(164, 69, NULL),
(164, 70, NULL),
(164, 73, NULL),
(164, 74, NULL),
(164, 75, NULL),
(164, 76, NULL);

-- --------------------------------------------------------

--
-- Table structure for table `reserve`
--

DROP TABLE IF EXISTS `reserve`;
CREATE TABLE IF NOT EXISTS `reserve` (
  `ReserveId` int(11) NOT NULL AUTO_INCREMENT,
  `RoomName` varchar(20) COLLATE utf8_unicode_ci NOT NULL,
  `CustomerId` int(11) NOT NULL,
  `Status` int(11) NOT NULL COMMENT '0: Live, 1: Deposit, 2: Reservation (phone), 3: Paid',
  `BeginDate` datetime NOT NULL,
  `TotalDays` int(11) NOT NULL,
  `LivedDays` int(11) DEFAULT NULL,
  `TotalPayment` float DEFAULT NULL,
  `Paid` float DEFAULT NULL,
  `NumberPersons` int(11) DEFAULT '1',
  PRIMARY KEY (`ReserveId`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=165 ;

--
-- Dumping data for table `reserve`
--

INSERT INTO `reserve` (`ReserveId`, `RoomName`, `CustomerId`, `Status`, `BeginDate`, `TotalDays`, `LivedDays`, `TotalPayment`, `Paid`, `NumberPersons`) VALUES
(38, 'sdhglsd', 9, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(6, 'sdhglsd', 1, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(7, 'sdhglsd', 1, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(8, 'sdhglsd', 1, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(9, 'sdhglsd', 1, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(10, 'sdhglsd', 2, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(11, 'sdhglsd', 2, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(12, 'sdhglsd', 2, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(13, 'sdhglsd', 2, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(14, 'sdhglsd', 3, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(15, 'sdhglsd', 3, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(16, 'sdhglsd', 3, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(17, 'sdhglsd', 3, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(18, 'sdhglsd', 4, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(19, 'sdhglsd', 4, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(20, 'sdhglsd', 4, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(21, 'sdhglsd', 4, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(22, 'sdhglsd', 5, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(23, 'sdhglsd', 5, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(24, 'sdhglsd', 5, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(25, 'sdhglsd', 5, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(26, 'sdhglsd', 6, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(27, 'sdhglsd', 6, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(28, 'sdhglsd', 6, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(29, 'sdhglsd', 6, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(30, 'sdhglsd', 7, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(31, 'sdhglsd', 7, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(32, 'sdhglsd', 7, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(33, 'sdhglsd', 7, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(34, 'sdhglsd', 8, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(35, 'sdhglsd', 8, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(36, 'sdhglsd', 8, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(37, 'sdhglsd', 8, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(158, 'P5324', 49, 3, '2012-08-16 11:18:40', 1111, 1111, 277750000, 277750000, 1),
(41, 'sdhglsd', 9, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(42, 'sdhglsd', 10, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(43, 'sdhglsd', 10, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(44, 'sdhglsd', 10, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(45, 'sdhglsd', 10, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(46, 'sdhglsd', 12, 0, '2012-08-07 14:46:00', 6, 1, 1500000, 0, 1),
(47, 'sdhglsd', 12, 0, '2012-08-07 14:46:00', 6, 1, 1500000, 0, 1),
(48, 'sdhglsd', 12, 0, '2012-08-07 14:46:00', 6, 1, 1500000, 0, 1),
(49, 'sdhglsd', 12, 0, '2012-08-07 14:46:00', 6, 1, 1500000, 0, 1),
(50, 'sdhglsd', 13, 0, '2012-08-07 14:46:16', 6, 1, 1500000, 0, 1),
(51, 'sdhglsd', 13, 0, '2012-08-07 14:46:16', 6, 1, 1500000, 0, 1),
(52, 'sdhglsd', 13, 0, '2012-08-07 14:46:16', 6, 1, 1500000, 0, 1),
(53, 'sdhglsd', 13, 0, '2012-08-07 14:46:16', 6, 1, 1500000, 0, 1),
(54, 'sdhglsd', 14, 0, '2012-08-07 14:46:39', 6, 1, 1500000, 0, 1),
(55, 'sdhglsd', 14, 0, '2012-08-07 14:46:39', 6, 1, 1500000, 0, 1),
(56, 'sdhglsd', 14, 0, '2012-08-07 14:46:39', 6, 1, 1500000, 0, 1),
(57, 'sdhglsd', 14, 0, '2012-08-07 14:46:39', 6, 1, 1500000, 0, 1),
(58, 'sdhglsd', 15, 0, '2012-08-07 14:46:53', 6, 1, 1500000, 0, 1),
(59, 'sdhglsd', 15, 0, '2012-08-07 14:46:53', 6, 1, 1500000, 0, 1),
(60, 'sdhglsd', 15, 0, '2012-08-07 14:46:53', 6, 1, 1500000, 0, 1),
(61, 'sdhglsd', 15, 0, '2012-08-07 14:46:53', 6, 1, 1500000, 0, 1),
(62, 'sdhglsd', 16, 0, '2012-08-07 14:47:05', 6, 1, 1500000, 0, 1),
(63, 'sdhglsd', 16, 0, '2012-08-07 14:47:05', 6, 1, 1500000, 0, 1),
(64, 'sdhglsd', 16, 0, '2012-08-07 14:47:05', 6, 1, 1500000, 0, 1),
(65, 'sdhglsd', 16, 0, '2012-08-07 14:47:05', 6, 1, 1500000, 0, 1),
(66, 'sdhglsd', 17, 0, '2012-08-07 14:48:51', 6, 1, 1500000, 0, 1),
(67, 'sdhglsd', 17, 0, '2012-08-07 14:48:51', 6, 1, 1500000, 0, 1),
(68, 'sdhglsd', 17, 0, '2012-08-07 14:48:51', 6, 1, 1500000, 0, 1),
(69, 'sdhglsd', 17, 0, '2012-08-07 14:48:51', 6, 1, 1500000, 0, 1),
(70, 'sdhglsd', 18, 0, '2012-08-07 14:49:19', 6, 1, 1500000, 0, 1),
(71, 'sdhglsd', 18, 0, '2012-08-07 14:49:19', 6, 1, 1500000, 0, 1),
(72, 'sdhglsd', 18, 0, '2012-08-07 14:49:19', 6, 1, 1500000, 0, 1),
(73, 'sdhglsd', 18, 0, '2012-08-07 14:49:19', 6, 1, 1500000, 0, 1),
(74, 'sdhglsd', 19, 0, '2012-08-08 09:20:38', 6, 1, 1500000, 0, 1),
(75, 'sdhglsd', 19, 0, '2012-08-08 09:20:38', 6, 1, 1500000, 0, 1),
(76, 'sdhglsd', 19, 0, '2012-08-08 09:20:38', 6, 1, 1500000, 0, 1),
(77, 'sdhglsd', 19, 0, '2012-08-08 09:20:38', 6, 1, 1500000, 0, 1),
(78, 'sdhglsd', 20, 0, '2012-08-08 09:27:50', 6, 1, 1500000, 0, 1),
(79, 'sdhglsd', 20, 0, '2012-08-08 09:27:50', 6, 1, 1500000, 0, 1),
(80, 'sdhglsd', 20, 0, '2012-08-08 09:27:50', 6, 1, 1500000, 0, 1),
(81, 'sdhglsd', 20, 0, '2012-08-08 09:27:50', 6, 1, 1500000, 0, 1),
(82, 'sdhglsd', 21, 0, '2012-08-08 09:51:16', 6, 1, 1500000, 0, 1),
(83, 'sdhglsd', 21, 0, '2012-08-08 09:51:16', 6, 1, 1500000, 0, 1),
(84, 'sdhglsd', 21, 0, '2012-08-08 09:51:16', 6, 1, 1500000, 0, 1),
(85, 'sdhglsd', 21, 0, '2012-08-08 09:51:16', 6, 1, 1500000, 0, 1),
(86, 'sdhglsd', 22, 0, '2012-08-08 09:51:41', 6, 1, 1500000, 0, 1),
(87, 'sdhglsd', 22, 0, '2012-08-08 09:51:41', 6, 1, 1500000, 0, 1),
(88, 'sdhglsd', 22, 0, '2012-08-08 09:51:41', 6, 1, 1500000, 0, 1),
(89, 'sdhglsd', 22, 0, '2012-08-08 09:51:41', 6, 1, 1500000, 0, 1),
(90, 'sdhglsd', 23, 0, '2012-08-08 10:10:01', 6, 1, 1500000, 0, 1),
(91, 'sdhglsd', 23, 0, '2012-08-08 10:10:01', 6, 1, 1500000, 0, 1),
(92, 'sdhglsd', 23, 0, '2012-08-08 10:10:01', 6, 1, 1500000, 0, 1),
(93, 'sdhglsd', 23, 0, '2012-08-08 10:10:01', 6, 1, 1500000, 0, 1),
(94, 'sdhglsd', 24, 0, '2012-08-08 10:10:35', 6, 1, 1500000, 0, 1),
(95, 'sdhglsd', 24, 0, '2012-08-08 10:10:35', 6, 1, 1500000, 0, 1),
(96, 'sdhglsd', 24, 0, '2012-08-08 10:10:35', 6, 1, 1500000, 0, 1),
(97, 'sdhglsd', 24, 0, '2012-08-08 10:10:35', 6, 1, 1500000, 0, 1),
(98, 'sdhglsd', 25, 0, '2012-08-08 10:13:04', 6, 1, 1500000, 0, 1),
(99, 'sdhglsd', 25, 0, '2012-08-08 10:13:04', 6, 1, 1500000, 0, 1),
(100, 'sdhglsd', 25, 0, '2012-08-08 10:13:04', 6, 1, 1500000, 0, 1),
(101, 'sdhglsd', 25, 0, '2012-08-08 10:13:04', 6, 1, 1500000, 0, 1),
(102, 'sdhglsd', 26, 0, '2012-08-08 10:13:44', 6, 1, 1500000, 0, 1),
(103, 'sdhglsd', 26, 0, '2012-08-08 10:13:44', 6, 1, 1500000, 0, 1),
(104, 'sdhglsd', 26, 0, '2012-08-08 10:13:44', 6, 1, 1500000, 0, 1),
(105, 'sdhglsd', 26, 0, '2012-08-08 10:13:44', 6, 1, 1500000, 0, 1),
(106, 'sdhglsd', 27, 0, '2012-08-08 10:14:49', 6, 1, 1500000, 0, 1),
(107, 'sdhglsd', 27, 0, '2012-08-08 10:14:49', 6, 1, 1500000, 0, 1),
(108, 'sdhglsd', 27, 0, '2012-08-08 10:14:49', 6, 1, 1500000, 0, 1),
(109, 'sdhglsd', 27, 0, '2012-08-08 10:14:49', 6, 1, 1500000, 0, 1),
(110, 'sdhglsd', 28, 0, '2012-08-08 10:16:09', 6, 1, 1500000, 0, 1),
(111, 'sdhglsd', 28, 0, '2012-08-08 10:16:09', 6, 1, 1500000, 0, 1),
(112, 'sdhglsd', 28, 0, '2012-08-08 10:16:09', 6, 1, 1500000, 0, 1),
(113, 'sdhglsd', 28, 0, '2012-08-08 10:16:09', 6, 1, 1500000, 0, 1),
(114, 'sdhglsd', 29, 0, '2012-08-08 10:16:40', 6, 1, 1500000, 0, 1),
(115, 'sdhglsd', 29, 0, '2012-08-08 10:16:40', 6, 1, 1500000, 0, 1),
(116, 'sdhglsd', 29, 0, '2012-08-08 10:16:40', 6, 1, 1500000, 0, 1),
(117, 'sdhglsd', 29, 0, '2012-08-08 10:16:40', 6, 1, 1500000, 0, 1),
(118, 'sdhglsd', 30, 0, '2012-08-08 10:17:02', 6, 1, 1500000, 0, 1),
(119, 'sdhglsd', 30, 0, '2012-08-08 10:17:02', 6, 1, 1500000, 0, 1),
(120, 'sdhglsd', 30, 0, '2012-08-08 10:17:02', 6, 1, 1500000, 0, 1),
(121, 'sdhglsd', 30, 0, '2012-08-08 10:17:02', 6, 1, 1500000, 0, 1),
(122, 'sdhglsd', 31, 0, '2012-08-08 10:17:46', 6, 1, 1500000, 0, 1),
(123, 'sdhglsd', 31, 0, '2012-08-08 10:17:46', 6, 1, 1500000, 0, 1),
(124, 'sdhglsd', 31, 0, '2012-08-08 10:17:46', 6, 1, 1500000, 0, 1),
(125, 'sdhglsd', 31, 0, '2012-08-08 10:17:46', 6, 1, 1500000, 0, 1),
(126, 'sdhglsd', 32, 0, '2012-08-08 10:17:55', 6, 1, 1500000, 0, 1),
(127, 'sdhglsd', 32, 0, '2012-08-08 10:17:55', 6, 1, 1500000, 0, 1),
(128, 'sdhglsd', 32, 0, '2012-08-08 10:17:55', 6, 1, 1500000, 0, 1),
(129, 'sdhglsd', 32, 0, '2012-08-08 10:17:55', 6, 1, 1500000, 0, 1),
(130, 'sdhglsd', 33, 0, '2012-08-08 10:18:13', 6, 1, 1500000, 0, 1),
(131, 'sdhglsd', 33, 0, '2012-08-08 10:18:13', 6, 1, 1500000, 0, 1),
(132, 'sdhglsd', 33, 0, '2012-08-08 10:18:13', 6, 1, 1500000, 0, 1),
(133, 'sdhglsd', 33, 0, '2012-08-08 10:18:13', 6, 1, 1500000, 0, 1),
(134, 'sdhglsd', 34, 0, '2012-08-08 10:18:29', 6, 1, 1500000, 0, 1),
(135, 'sdhglsd', 34, 0, '2012-08-08 10:18:29', 6, 1, 1500000, 0, 1),
(136, 'sdhglsd', 34, 0, '2012-08-08 10:18:29', 6, 1, 1500000, 0, 1),
(137, 'sdhglsd', 34, 0, '2012-08-08 10:18:29', 6, 1, 1500000, 0, 1),
(138, 'sdhglsd', 35, 0, '2012-08-08 10:25:28', 6, 1, 1500000, 0, 1),
(139, 'sdhglsd', 35, 0, '2012-08-08 10:25:28', 6, 1, 1500000, 0, 1),
(140, 'sdhglsd', 35, 0, '2012-08-08 10:25:28', 6, 1, 1500000, 0, 1),
(141, 'sdhglsd', 35, 0, '2012-08-08 10:25:28', 6, 1, 1500000, 0, 1),
(142, 'sdhglsd', 36, 0, '2012-08-08 10:27:52', 6, 1, 1500000, 0, 1),
(143, 'sdhglsd', 36, 0, '2012-08-08 10:27:52', 6, 1, 1500000, 0, 1),
(144, 'sdhglsd', 36, 0, '2012-08-08 10:27:52', 6, 1, 1500000, 0, 1),
(145, 'sdhglsd', 36, 0, '2012-08-08 10:27:52', 6, 1, 1500000, 0, 1),
(146, 'sdhglsd', 37, 0, '2012-08-08 10:31:52', 6, 1, 1500000, 0, 1),
(147, 'sdhglsd', 37, 0, '2012-08-08 10:31:52', 6, 1, 1500000, 0, 1),
(148, 'sdhglsd', 37, 0, '2012-08-08 10:31:52', 6, 1, 1500000, 0, 1),
(149, 'sdhglsd', 37, 0, '2012-08-08 10:31:52', 6, 1, 1500000, 0, 1),
(150, 'P5324', 8, 0, '2012-08-16 10:12:02', 252, 0, 63000000, 0, 1),
(152, 'dsfgdsfg', 40, 0, '2012-08-16 10:12:02', 252, 0, 555555, 0, 1),
(153, 'P5324', 47, 3, '2012-08-16 10:12:02', 252, 0, 6666, 0, 1),
(154, 'sdhglsd', 42, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(155, 'P5324', 43, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(156, 'sdhglsd', 44, 0, '2012-08-07 00:00:00', 6, 1, 1500000, 0, 1),
(157, 'sdhglsd', 51, 0, '2012-08-08 10:13:44', 6, 1, 1500000, 0, 1),
(159, 'dsfgdsfg', 60, 3, '2012-08-16 11:19:37', 10, 10, 2500000, 2500000, 1),
(160, 'dsfgdsfg', 65, 3, '2012-08-22 09:02:46', 14234324, 14234324, 3558580000000, 3558580000000, 1),
(161, 'P5324', 41, 3, '2012-08-22 09:02:46', 14234324, 14234324, 3558580000000, 3558580000000, 1),
(163, 'P5324', 66, 0, '2012-08-22 09:13:34', 1056936115, 0, 264234000000000, 0, 1),
(164, 'dsfgdsfg', 1, 3, '2012-08-22 09:14:31', 3563256, 3563256, 9059360000000, 4059360000000, 10);

-- --------------------------------------------------------

--
-- Table structure for table `room`
--

DROP TABLE IF EXISTS `room`;
CREATE TABLE IF NOT EXISTS `room` (
  `RoomName` varchar(20) COLLATE utf8_unicode_ci NOT NULL,
  `RoomTypeName` varchar(20) COLLATE utf8_unicode_ci NOT NULL,
  `RoomFloor` int(11) DEFAULT NULL,
  PRIMARY KEY (`RoomName`),
  UNIQUE KEY `RoomName` (`RoomName`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `room`
--

INSERT INTO `room` (`RoomName`, `RoomTypeName`, `RoomFloor`) VALUES
('P5324', 'Type 1', 356325632),
('sdhglsd', 'Type 1', 5555),
('dsfgdsfg', 'Type 1', 43);

-- --------------------------------------------------------

--
-- Table structure for table `roomtype`
--

DROP TABLE IF EXISTS `roomtype`;
CREATE TABLE IF NOT EXISTS `roomtype` (
  `RoomTypeName` varchar(20) COLLATE utf8_unicode_ci NOT NULL,
  `Price` float NOT NULL,
  PRIMARY KEY (`RoomTypeName`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `roomtype`
--

INSERT INTO `roomtype` (`RoomTypeName`, `Price`) VALUES
('Type 1', 2542440),
('Type 2', 300000),
('Type 3', 480000),
('Type 4', 600000);

-- --------------------------------------------------------

--
-- Table structure for table `service`
--

DROP TABLE IF EXISTS `service`;
CREATE TABLE IF NOT EXISTS `service` (
  `ServiceName` varchar(50) COLLATE utf8_unicode_ci NOT NULL,
  `ServiceType` varchar(20) COLLATE utf8_unicode_ci DEFAULT NULL,
  `Price` float DEFAULT NULL,
  `Unit` varchar(20) COLLATE utf8_unicode_ci DEFAULT NULL,
  `Description` varchar(100) COLLATE utf8_unicode_ci DEFAULT NULL,
  PRIMARY KEY (`ServiceName`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `service`
--

INSERT INTO `service` (`ServiceName`, `ServiceType`, `Price`, `Unit`, `Description`) VALUES
('hjfgj', 'gfjfg', 21525, 'wertew', 'weyweu'),
('adfa', 'sagas', 0, 'asg', 'ncnqrqet'),
('dshds', 'sdhsd', 0, 'sdhsd', 'sdh');

-- --------------------------------------------------------

--
-- Table structure for table `serviceextras`
--

DROP TABLE IF EXISTS `serviceextras`;
CREATE TABLE IF NOT EXISTS `serviceextras` (
  `ReserveId` int(11) NOT NULL,
  `ServiceName` varchar(20) COLLATE utf8_unicode_ci NOT NULL,
  `Quantity` int(11) NOT NULL,
  `TotalPrice` float NOT NULL,
  PRIMARY KEY (`ReserveId`,`ServiceName`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `serviceextras`
--

INSERT INTO `serviceextras` (`ReserveId`, `ServiceName`, `Quantity`, `TotalPrice`) VALUES
(6, 'hjfgj', 1, 1414640),
(6, 'adfa', 5236, 56737),
(6, 'dshds', 23241, 54215);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
