/*
 Navicat Premium Dump SQL

 Source Server         : Lead (local)
 Source Server Type    : MySQL
 Source Server Version : 50651 (5.6.51)
 Source Host           : localhost:3306
 Source Schema         : log

 Target Server Type    : MySQL
 Target Server Version : 50651 (5.6.51)
 File Encoding         : 65001

 Date: 18/01/2026 07:39:38
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for bootlog
-- ----------------------------
DROP TABLE IF EXISTS `bootlog`;
CREATE TABLE `bootlog`  (
  `time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `hostname` char(128) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT 'UNKNOWN',
  `channel` tinyint(1) NOT NULL DEFAULT 0
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of bootlog
-- ----------------------------
INSERT INTO `bootlog` VALUES ('2026-01-12 21:41:08', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-12 21:41:13', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-12 21:41:13', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-12 21:41:13', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-12 21:41:55', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-12 21:41:55', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-12 21:41:55', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-12 21:42:40', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-12 21:42:40', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-12 21:42:40', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-13 22:51:05', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-13 22:51:06', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-13 22:51:08', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-13 22:52:48', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-13 22:52:49', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-13 22:52:50', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-13 22:52:50', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:52:56', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:52:56', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:52:58', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:52:58', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:53:07', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:53:07', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:53:08', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:53:09', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:55:10', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:55:11', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:55:12', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:55:12', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:56:33', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:56:34', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:56:35', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:56:36', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:56:38', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:56:39', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:56:40', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:56:41', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:57:54', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:57:54', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:57:55', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:57:56', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:58:25', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:58:26', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:58:27', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:58:27', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:58:48', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:58:49', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:58:49', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 18:58:50', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-16 19:00:24', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 19:01:13', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 19:02:36', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 19:02:48', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 19:02:49', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 19:02:50', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 19:02:50', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-16 22:32:39', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 22:32:40', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 22:32:40', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-16 22:32:40', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:21:34', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:21:35', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:21:36', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:21:37', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:22:31', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:22:32', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:22:33', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:22:34', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:23:39', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:23:40', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:23:41', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:23:41', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:26:06', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:26:07', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:26:08', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:26:09', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:27:50', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:27:51', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:27:52', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:27:52', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:31:17', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:31:18', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:31:19', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:31:19', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:36:57', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:36:59', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:36:59', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:37:00', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:47:31', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:47:32', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:47:32', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:47:33', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:49:00', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:49:01', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:49:02', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:49:02', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:50:37', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:50:38', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:50:39', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-17 16:50:39', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:12:19', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:12:20', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:12:21', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:12:22', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:13:41', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:13:42', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:13:42', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:13:43', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:14:22', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:14:23', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:14:24', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:14:24', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:41:16', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:41:16', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:41:16', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:41:16', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:42:00', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:42:00', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:42:00', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:42:00', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:55:15', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:55:17', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:55:18', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:55:19', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:55:45', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:55:45', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:55:46', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-18 05:55:47', 'Game99', 99);
INSERT INTO `bootlog` VALUES ('2026-01-18 06:36:38', 'Game1', 1);
INSERT INTO `bootlog` VALUES ('2026-01-18 06:36:40', 'Auth01', 1);
INSERT INTO `bootlog` VALUES ('2026-01-18 06:36:40', 'Game2', 1);
INSERT INTO `bootlog` VALUES ('2026-01-18 06:36:41', 'Game99', 99);

-- ----------------------------
-- Table structure for change_name
-- ----------------------------
DROP TABLE IF EXISTS `change_name`;
CREATE TABLE `change_name`  (
  `pid` int(11) NULL DEFAULT NULL,
  `old_name` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `new_name` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `time` datetime NULL DEFAULT NULL,
  `ip` varchar(20) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of change_name
-- ----------------------------

-- ----------------------------
-- Table structure for command_log
-- ----------------------------
DROP TABLE IF EXISTS `command_log`;
CREATE TABLE `command_log`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `userid` int(11) NOT NULL DEFAULT 0,
  `server` int(11) NOT NULL DEFAULT 0,
  `ip` varchar(15) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `port` int(6) NOT NULL DEFAULT 0,
  `username` varchar(50) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `command` text CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `date` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of command_log
-- ----------------------------

-- ----------------------------
-- Table structure for cube
-- ----------------------------
DROP TABLE IF EXISTS `cube`;
CREATE TABLE `cube`  (
  `id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `pid` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `x` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `y` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `item_vnum` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `item_uid` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `item_count` int(5) UNSIGNED NOT NULL DEFAULT 0,
  `success` tinyint(1) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`) USING BTREE,
  INDEX `pid`(`pid`) USING BTREE,
  INDEX `item_vnum`(`item_vnum`) USING BTREE,
  INDEX `item_uid`(`item_uid`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of cube
-- ----------------------------

-- ----------------------------
-- Table structure for dragon_slay_log
-- ----------------------------
DROP TABLE IF EXISTS `dragon_slay_log`;
CREATE TABLE `dragon_slay_log`  (
  `guild_id` int(11) UNSIGNED NOT NULL,
  `vnum` int(11) UNSIGNED NOT NULL,
  `start_time` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `end_time` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00'
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of dragon_slay_log
-- ----------------------------

-- ----------------------------
-- Table structure for fish_log
-- ----------------------------
DROP TABLE IF EXISTS `fish_log`;
CREATE TABLE `fish_log`  (
  `time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `player_id` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `map_index` tinyint(4) NOT NULL DEFAULT 0,
  `fish_id` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `fishing_level` int(11) NOT NULL DEFAULT 0,
  `waiting_time` int(11) NOT NULL DEFAULT 0,
  `success` tinyint(4) NOT NULL DEFAULT 0,
  `size` smallint(6) NOT NULL DEFAULT 0
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of fish_log
-- ----------------------------

-- ----------------------------
-- Table structure for goldlog
-- ----------------------------
DROP TABLE IF EXISTS `goldlog`;
CREATE TABLE `goldlog`  (
  `date` varchar(10) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '0000-00-00',
  `time` varchar(8) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '00:00:00',
  `pid` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `what` int(11) NOT NULL DEFAULT 0,
  `how` set('BUY','SELL','SHOP_SELL','SHOP_BUY','EXCHANGE_TAKE','EXCHANGE_GIVE','QUEST') CHARACTER SET big5 COLLATE big5_chinese_ci NULL DEFAULT NULL,
  `hint` varchar(50) CHARACTER SET big5 COLLATE big5_chinese_ci NULL DEFAULT NULL,
  INDEX `date_idx`(`date`) USING BTREE,
  INDEX `pid_idx`(`pid`) USING BTREE,
  INDEX `what_idx`(`what`) USING BTREE,
  INDEX `how_idx`(`how`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of goldlog
-- ----------------------------

-- ----------------------------
-- Table structure for hack_crc_log
-- ----------------------------
DROP TABLE IF EXISTS `hack_crc_log`;
CREATE TABLE `hack_crc_log`  (
  `time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `login` char(16) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `name` char(24) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `ip` char(15) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `server` char(100) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `why` char(255) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `crc` int(11) NOT NULL DEFAULT 0
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of hack_crc_log
-- ----------------------------

-- ----------------------------
-- Table structure for hack_log
-- ----------------------------
DROP TABLE IF EXISTS `hack_log`;
CREATE TABLE `hack_log`  (
  `time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `login` char(16) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `name` char(24) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `ip` char(15) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `server` char(100) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `why` char(255) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT ''
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of hack_log
-- ----------------------------

-- ----------------------------
-- Table structure for levellog
-- ----------------------------
DROP TABLE IF EXISTS `levellog`;
CREATE TABLE `levellog`  (
  `name` char(24) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `level` tinyint(4) NOT NULL DEFAULT 0,
  `time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `playtime` int(11) NOT NULL DEFAULT 0,
  `account_id` int(11) NOT NULL,
  `pid` int(11) NOT NULL,
  PRIMARY KEY (`name`, `level`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of levellog
-- ----------------------------

-- ----------------------------
-- Table structure for log
-- ----------------------------
DROP TABLE IF EXISTS `log`;
CREATE TABLE `log`  (
  `type` enum('ITEM','CHARACTER') CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT 'ITEM',
  `time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `who` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `x` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `y` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `what` int(11) NOT NULL DEFAULT 0,
  `how` varchar(50) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `hint` varchar(70) CHARACTER SET big5 COLLATE big5_chinese_ci NULL DEFAULT NULL,
  `ip` varchar(20) CHARACTER SET big5 COLLATE big5_chinese_ci NULL DEFAULT NULL,
  `vnum` int(11) NULL DEFAULT NULL,
  INDEX `who_idx`(`who`) USING BTREE,
  INDEX `what_idx`(`what`) USING BTREE,
  INDEX `how_idx`(`how`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of log
-- ----------------------------
INSERT INTO `log` VALUES ('CHARACTER', '2026-01-12 21:47:20', 3, 0, 0, 0, 'CREATE PLAYER', '', '127.0.0.1', NULL);
INSERT INTO `log` VALUES ('CHARACTER', '2026-01-12 21:47:25', 3, 957278, 255158, 0, 'LOGIN', '172.24.144.1 0 1 41 0', '172.24.144.1', NULL);
INSERT INTO `log` VALUES ('CHARACTER', '2026-01-12 21:47:29', 3, 957278, 255158, 0, 'LOGOUT', '172.24.144.1 0 1 41 0', '172.24.144.1', NULL);
INSERT INTO `log` VALUES ('CHARACTER', '2026-01-12 21:48:32', 3, 957278, 255158, 0, 'LOGIN', '172.24.144.1 0 1 41 0', '172.24.144.1', NULL);
INSERT INTO `log` VALUES ('CHARACTER', '2026-01-12 21:48:34', 3, 957278, 255158, 0, 'LOGOUT', '172.24.144.1 0 1 41 0', '172.24.144.1', NULL);
INSERT INTO `log` VALUES ('CHARACTER', '2026-01-12 21:49:35', 3, 957278, 255158, 0, 'LOGIN', '172.24.144.1 0 1 41 0', '172.24.144.1', NULL);
INSERT INTO `log` VALUES ('ITEM', '2026-01-12 21:49:38', 3, 957278, 255158, 20000174, 'SYSTEM', 'Apprentice Chest I', '172.24.144.1', 50187);
INSERT INTO `log` VALUES ('CHARACTER', '2026-01-12 21:49:59', 3, 957459, 255389, 0, 'LOGOUT', '172.24.144.1 0 1 41 0', '172.24.144.1', NULL);
INSERT INTO `log` VALUES ('CHARACTER', '2026-01-13 22:55:02', 3, 957459, 255389, 0, 'LOGIN', '172.24.144.1 0 1 41 0', '172.24.144.1', NULL);
INSERT INTO `log` VALUES ('CHARACTER', '2026-01-13 22:55:16', 3, 957459, 255389, 0, 'LOGOUT', '172.24.144.1 0 1 41 0', '172.24.144.1', NULL);
INSERT INTO `log` VALUES ('CHARACTER', '2026-01-16 22:33:06', 3, 957459, 255389, 0, 'LOGIN', '172.24.144.1 0 1 41 0', '172.24.144.1', NULL);
INSERT INTO `log` VALUES ('ITEM', '2026-01-16 22:33:14', 3, 957459, 255389, 40000099, 'SYSTEM', 'Apprentice Chest II', '172.24.144.1', 50188);
INSERT INTO `log` VALUES ('ITEM', '2026-01-16 22:33:14', 0, 1, 0, 40000100, 'SET_SOCKET', '', '', 10);
INSERT INTO `log` VALUES ('ITEM', '2026-01-16 22:33:14', 3, 957459, 255389, 40000100, 'SYSTEM', 'Sword+0', '172.24.144.1', 10);
INSERT INTO `log` VALUES ('ITEM', '2026-01-16 22:33:14', 3, 957459, 255389, 40000101, 'SYSTEM', 'Red Potion (S)', '172.24.144.1', 27051);
INSERT INTO `log` VALUES ('ITEM', '2026-01-16 22:33:14', 3, 957459, 255389, 40000102, 'SYSTEM', 'Blue Potion (S)', '172.24.144.1', 27052);
INSERT INTO `log` VALUES ('ITEM', '2026-01-16 22:33:14', 3, 957459, 255389, 40000103, 'SYSTEM', 'Green Potion (S)', '172.24.144.1', 27053);
INSERT INTO `log` VALUES ('ITEM', '2026-01-16 22:33:14', 3, 957459, 255389, 40000104, 'SYSTEM', 'Purple Potion (S)', '172.24.144.1', 27054);
INSERT INTO `log` VALUES ('CHARACTER', '2026-01-16 22:33:44', 3, 957474, 259412, 0, 'LOGOUT', '172.24.144.1 0 1 41 0', '172.24.144.1', NULL);
INSERT INTO `log` VALUES ('CHARACTER', '2026-01-16 22:35:21', 3, 957474, 259412, 0, 'LOGIN', '172.24.144.1 0 1 41 0', '172.24.144.1', NULL);
INSERT INTO `log` VALUES ('CHARACTER', '2026-01-16 22:41:17', 3, 957294, 259678, 0, 'LOGOUT', '172.24.144.1 0 1 41 10', '172.24.144.1', NULL);
INSERT INTO `log` VALUES ('CHARACTER', '2026-01-16 22:43:11', 3, 957294, 259678, 0, 'LOGIN', '172.24.144.1 0 1 41 25', '172.24.144.1', NULL);
INSERT INTO `log` VALUES ('CHARACTER', '2026-01-16 22:43:34', 3, 957294, 259678, 0, 'LOGOUT', '172.24.144.1 0 1 41 25', '172.24.144.1', NULL);
INSERT INTO `log` VALUES ('CHARACTER', '2026-01-17 16:24:45', 3, 957294, 259678, 0, 'LOGIN', '172.24.144.1 0 1 41 25', '172.24.144.1', NULL);
INSERT INTO `log` VALUES ('CHARACTER', '2026-01-17 16:38:33', 3, 957294, 259678, 0, 'LOGIN', '172.24.144.1 0 1 41 25', '172.24.144.1', NULL);
INSERT INTO `log` VALUES ('CHARACTER', '2026-01-17 16:38:54', 3, 957294, 259678, 0, 'LOGOUT', '172.24.144.1 0 1 41 25', '172.24.144.1', NULL);
INSERT INTO `log` VALUES ('CHARACTER', '2026-01-17 16:51:21', 3, 957294, 259678, 5, 'GM_LOGIN', '', '172.24.144.1', NULL);
INSERT INTO `log` VALUES ('CHARACTER', '2026-01-17 16:51:21', 3, 957294, 259678, 0, 'LOGIN', '172.24.144.1 0 1 41 25', '172.24.144.1', NULL);
INSERT INTO `log` VALUES ('CHARACTER', '2026-01-17 16:51:32', 3, 957350, 260743, 0, 'LOGOUT', '172.24.144.1 0 1 41 25', '172.24.144.1', NULL);
INSERT INTO `log` VALUES ('CHARACTER', '2026-01-18 06:37:52', 3, 957350, 260743, 5, 'GM_LOGIN', '', '172.24.144.1', NULL);
INSERT INTO `log` VALUES ('CHARACTER', '2026-01-18 06:37:52', 3, 957350, 260743, 0, 'LOGIN', '172.24.144.1 0 1 41 25', '172.24.144.1', NULL);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 0, 1, 0, 40000105, 'SET_SOCKET', '', '', 11299);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 1, 1, 0, 40000105, 'SET_SOCKET', '', '', 11299);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 2, 1, 0, 40000105, 'SET_SOCKET', '', '', 11299);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 0, 1, 0, 40000108, 'SET_SOCKET', '', '', 3159);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 1, 1, 0, 40000108, 'SET_SOCKET', '', '', 3159);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 2, 1, 0, 40000108, 'SET_SOCKET', '', '', 3159);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 0, 7, 8, 40000109, 'SET_FORCE_ATTR', '', '172.24.144.1', 12249);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 1, 10, 30, 40000109, 'SET_FORCE_ATTR', '', '172.24.144.1', 12249);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 2, 11, 30, 40000109, 'SET_FORCE_ATTR', '', '172.24.144.1', 12249);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 3, 28, 15, 40000109, 'SET_FORCE_ATTR', '', '172.24.144.1', 12249);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 4, 24, 10, 40000109, 'SET_FORCE_ATTR', '', '172.24.144.1', 12249);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 0, 9, 20, 40000108, 'SET_FORCE_ATTR', '', '172.24.144.1', 3159);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 1, 15, 10, 40000108, 'SET_FORCE_ATTR', '', '172.24.144.1', 3159);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 2, 16, 10, 40000108, 'SET_FORCE_ATTR', '', '172.24.144.1', 3159);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 3, 22, 20, 40000108, 'SET_FORCE_ATTR', '', '172.24.144.1', 3159);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 4, 5, 12, 40000108, 'SET_FORCE_ATTR', '', '172.24.144.1', 3159);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 0, 3, 12, 40000106, 'SET_FORCE_ATTR', '', '172.24.144.1', 13049);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 1, 27, 15, 40000106, 'SET_FORCE_ATTR', '', '172.24.144.1', 13049);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 2, 39, 10, 40000106, 'SET_FORCE_ATTR', '', '172.24.144.1', 13049);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 3, 48, 1, 40000106, 'SET_FORCE_ATTR', '', '172.24.144.1', 13049);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 4, 49, 1, 40000106, 'SET_FORCE_ATTR', '', '172.24.144.1', 13049);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 0, 1, 2000, 40000105, 'SET_FORCE_ATTR', '', '172.24.144.1', 11299);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 1, 9, 20, 40000105, 'SET_FORCE_ATTR', '', '172.24.144.1', 11299);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 2, 23, 10, 40000105, 'SET_FORCE_ATTR', '', '172.24.144.1', 11299);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 3, 39, 10, 40000105, 'SET_FORCE_ATTR', '', '172.24.144.1', 11299);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 4, 53, 50, 40000105, 'SET_FORCE_ATTR', '', '172.24.144.1', 11299);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 0, 1, 2000, 40000107, 'SET_FORCE_ATTR', '', '172.24.144.1', 15189);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 1, 2, 80, 40000107, 'SET_FORCE_ATTR', '', '172.24.144.1', 15189);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 2, 8, 8, 40000107, 'SET_FORCE_ATTR', '', '172.24.144.1', 15189);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 3, 7, 8, 40000107, 'SET_FORCE_ATTR', '', '172.24.144.1', 15189);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 4, 15, 10, 40000107, 'SET_FORCE_ATTR', '', '172.24.144.1', 15189);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 0, 1, 2000, 40000110, 'SET_FORCE_ATTR', '', '172.24.144.1', 14109);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 1, 2, 80, 40000110, 'SET_FORCE_ATTR', '', '172.24.144.1', 14109);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 2, 16, 10, 40000110, 'SET_FORCE_ATTR', '', '172.24.144.1', 14109);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 3, 23, 10, 40000110, 'SET_FORCE_ATTR', '', '172.24.144.1', 14109);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 4, 25, 10, 40000110, 'SET_FORCE_ATTR', '', '172.24.144.1', 14109);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 0, 1, 2000, 40000112, 'SET_FORCE_ATTR', '', '172.24.144.1', 16109);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 1, 2, 80, 40000112, 'SET_FORCE_ATTR', '', '172.24.144.1', 16109);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 2, 15, 10, 40000112, 'SET_FORCE_ATTR', '', '172.24.144.1', 16109);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 3, 16, 10, 40000112, 'SET_FORCE_ATTR', '', '172.24.144.1', 16109);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 4, 24, 10, 40000112, 'SET_FORCE_ATTR', '', '172.24.144.1', 16109);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 0, 8, 20, 40000111, 'SET_FORCE_ATTR', '', '172.24.144.1', 17109);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 1, 25, 10, 40000111, 'SET_FORCE_ATTR', '', '172.24.144.1', 17109);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 2, 41, 5, 40000111, 'SET_FORCE_ATTR', '', '172.24.144.1', 17109);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 3, 22, 20, 40000111, 'SET_FORCE_ATTR', '', '172.24.144.1', 17109);
INSERT INTO `log` VALUES ('ITEM', '2026-01-18 06:38:02', 4, 21, 20, 40000111, 'SET_FORCE_ATTR', '', '172.24.144.1', 17109);
INSERT INTO `log` VALUES ('CHARACTER', '2026-01-18 06:38:08', 3, 957528, 261001, 0, 'LOGOUT', '172.24.144.1 0 1 41 25', '172.24.144.1', NULL);

-- ----------------------------
-- Table structure for loginlog
-- ----------------------------
DROP TABLE IF EXISTS `loginlog`;
CREATE TABLE `loginlog`  (
  `type` enum('LOGIN','LOGOUT') CHARACTER SET big5 COLLATE big5_chinese_ci NULL DEFAULT NULL,
  `time` datetime NULL DEFAULT NULL,
  `channel` tinyint(4) NULL DEFAULT NULL,
  `account_id` int(10) UNSIGNED NULL DEFAULT NULL,
  `pid` int(10) UNSIGNED NULL DEFAULT NULL,
  `level` smallint(6) NULL DEFAULT NULL,
  `job` tinyint(4) NULL DEFAULT NULL,
  `playtime` int(10) UNSIGNED NULL DEFAULT NULL,
  INDEX `pid`(`pid`, `type`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of loginlog
-- ----------------------------

-- ----------------------------
-- Table structure for loginlog2
-- ----------------------------
DROP TABLE IF EXISTS `loginlog2`;
CREATE TABLE `loginlog2`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `type` text CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL,
  `is_gm` int(11) NULL DEFAULT NULL,
  `login_time` datetime NULL DEFAULT NULL,
  `channel` int(11) NULL DEFAULT NULL,
  `account_id` int(11) NULL DEFAULT NULL,
  `pid` int(11) NULL DEFAULT NULL,
  `client_version` text CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL,
  `ip` text CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL,
  `logout_time` datetime NULL DEFAULT NULL,
  `playtime` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of loginlog2
-- ----------------------------

-- ----------------------------
-- Table structure for money_log
-- ----------------------------
DROP TABLE IF EXISTS `money_log`;
CREATE TABLE `money_log`  (
  `time` datetime NULL DEFAULT NULL,
  `type` enum('MONSTER','SHOP','REFINE','QUEST','GUILD','MISC','KILL','DROP') CHARACTER SET big5 COLLATE big5_chinese_ci NULL DEFAULT NULL,
  `vnum` int(11) NOT NULL DEFAULT 0,
  `gold` int(11) NOT NULL DEFAULT 0,
  INDEX `type`(`type`, `vnum`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of money_log
-- ----------------------------

-- ----------------------------
-- Table structure for playercount
-- ----------------------------
DROP TABLE IF EXISTS `playercount`;
CREATE TABLE `playercount`  (
  `date` datetime NULL DEFAULT NULL,
  `count_red` int(11) NULL DEFAULT NULL,
  `count_yellow` int(11) NULL DEFAULT NULL,
  `count_blue` int(11) NULL DEFAULT NULL,
  `count_total` int(11) NULL DEFAULT NULL
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of playercount
-- ----------------------------

-- ----------------------------
-- Table structure for quest_reward_log
-- ----------------------------
DROP TABLE IF EXISTS `quest_reward_log`;
CREATE TABLE `quest_reward_log`  (
  `quest_name` varchar(32) CHARACTER SET big5 COLLATE big5_chinese_ci NULL DEFAULT NULL,
  `player_id` int(10) UNSIGNED NULL DEFAULT NULL,
  `player_level` tinyint(4) NULL DEFAULT NULL,
  `reward_type` enum('EXP','ITEM') CHARACTER SET big5 COLLATE big5_chinese_ci NULL DEFAULT NULL,
  `reward_value1` int(10) UNSIGNED NULL DEFAULT NULL,
  `reward_value2` int(11) NULL DEFAULT NULL,
  `time` datetime NULL DEFAULT NULL,
  INDEX `player_id`(`player_id`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of quest_reward_log
-- ----------------------------
INSERT INTO `quest_reward_log` VALUES ('give_basic_weapon', 3, 1, 'ITEM', 50187, 1, '2026-01-12 21:49:38');

-- ----------------------------
-- Table structure for refinelog
-- ----------------------------
DROP TABLE IF EXISTS `refinelog`;
CREATE TABLE `refinelog`  (
  `pid` int(10) UNSIGNED NULL DEFAULT NULL,
  `item_name` varchar(24) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `item_id` int(11) NOT NULL DEFAULT 0,
  `step` varchar(50) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `is_success` tinyint(1) NOT NULL DEFAULT 0,
  `setType` set('SOCKET','POWER','ROD','GUILD','SCROLL','HYUNIRON','GOD_SCROLL','MUSIN_SCROLL') CHARACTER SET big5 COLLATE big5_chinese_ci NULL DEFAULT NULL
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of refinelog
-- ----------------------------

-- ----------------------------
-- Table structure for shout_log
-- ----------------------------
DROP TABLE IF EXISTS `shout_log`;
CREATE TABLE `shout_log`  (
  `time` datetime NULL DEFAULT '0000-00-00 00:00:00',
  `channel` tinyint(4) NULL DEFAULT NULL,
  `empire` tinyint(4) NULL DEFAULT NULL,
  `shout` varchar(350) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  INDEX `time_idx`(`time`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of shout_log
-- ----------------------------

-- ----------------------------
-- Table structure for speed_hack
-- ----------------------------
DROP TABLE IF EXISTS `speed_hack`;
CREATE TABLE `speed_hack`  (
  `pid` int(11) NULL DEFAULT NULL,
  `time` datetime NULL DEFAULT NULL,
  `x` int(11) NULL DEFAULT NULL,
  `y` int(11) NULL DEFAULT NULL,
  `hack_count` varchar(20) CHARACTER SET big5 COLLATE big5_bin NULL DEFAULT NULL
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of speed_hack
-- ----------------------------

SET FOREIGN_KEY_CHECKS = 1;
