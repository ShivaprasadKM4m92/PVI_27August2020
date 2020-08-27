Action()
{

	web_set_sockets_option("SSL_VERSION", "TLS");
	
	web_cleanup_auto_headers();

	lr_start_transaction("FollowUp_01_OpenApplication");
	
	web_add_header("Accept", 
		"text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9");

	web_add_header("Accept-Encoding", 
		"gzip, deflate");

	web_add_auto_header("Accept-Language", 
		"en-US,en;q=0.9");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("User-Agent", 
		"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.135 Safari/537.36");

	web_reg_find("Search=Body",
		"Text=Login",
		LAST);

	web_url("external", 
		"URL={PV_Admin_URL}/external", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTTP", 
		LAST);

	
	web_revert_auto_header("Accept-Language");

	web_add_header("A-IM", 
		"x-bm,gzip");


	web_revert_auto_header("Sec-Fetch-Dest");

	web_revert_auto_header("Sec-Fetch-Site");

	web_add_header("Accept", 
		"text/css,*/*;q=0.1");

	web_add_auto_header("Accept-Encoding", 
		"gzip, deflate");

	web_add_auto_header("Accept-Language", 
		"en-US,en;q=0.9");
	
	web_concurrent_start(NULL);

	web_url("login-17e4cb116ee46711bb739b7018d00771.css", 
		"URL={PV_Admin_URL}/assets/login-17e4cb116ee46711bb739b7018d00771.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer={PV_Admin_URL}/external", 
		"Snapshot=t4.inf", 
		LAST);

//	web_add_auto_header("Accept", 
//		"*/*");

	web_url("bootstrap.min-79b5346433d3bdf736aab2379a008083.js", 
		"URL={PV_Admin_URL}/assets/vendorUi/bootstrap/bootstrap.min-79b5346433d3bdf736aab2379a008083.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={PV_Admin_URL}/external", 
		"Snapshot=t5.inf", 
		LAST);

	web_url("jquery.core-2521768e514d3a431ddca828a1bebd3c.js", 
		"URL={PV_Admin_URL}/assets/common/jquery.core-2521768e514d3a431ddca828a1bebd3c.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={PV_Admin_URL}/external", 
		"Snapshot=t6.inf", 
		LAST);

	web_url("notify.min-a1134657dba6e98914066f2530604e68.js", 
		"URL={PV_Admin_URL}/assets/vendorUi/notifyjs/dist/notify.min-a1134657dba6e98914066f2530604e68.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={PV_Admin_URL}/external", 
		"Snapshot=t7.inf", 
		LAST);

	web_url("notify-metro-3463085bfd0a7cac9f983d075b271bca.js", 
		"URL={PV_Admin_URL}/assets/vendorUi/notifications/notify-metro-3463085bfd0a7cac9f983d075b271bca.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={PV_Admin_URL}/external", 
		"Snapshot=t8.inf", 
		LAST);

	web_url("jquery-fdb24ba38c94d04e948de967076c64aa.js", 
		"URL={PV_Admin_URL}/assets/vendorUi/jquery/jquery-fdb24ba38c94d04e948de967076c64aa.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={PV_Admin_URL}/external", 
		"Snapshot=t9.inf", 
		LAST);

//	web_add_auto_header("Accept", 
//		"text/css,*/*;q=0.1");

	web_url("bootstrap-c5ae98cdc147f655f96564c4340000c4.css", 
		"URL={PV_Admin_URL}/assets/bootstrap-c5ae98cdc147f655f96564c4340000c4.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer={PV_Admin_URL}/external", 
		"Snapshot=t10.inf", 
		LAST);
	
	web_concurrent_end(NULL);
	

	lr_end_transaction("FollowUp_01_OpenApplication",LR_AUTO);

	lr_think_time(3);
	
	lr_start_transaction("FollowUp_02_Login");

	
	web_add_auto_header("Accept", 
		"text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9");

	web_add_auto_header("Accept-Encoding", 
		"gzip, deflate");

	web_add_header("Cache-Control", 
		"max-age=0");

	web_add_header("Origin", 
		"{PV_Admin_URL}");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

/*Correlation comment - Do not change!  Original value='60be058f-4bf3-4e25-ad91-91812f413835' Name ='TokenId' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=TokenId",
		"LB=token=",
		"RB=\r\n",
		SEARCH_FILTERS,
		"Scope=Headers",
		"IgnoreRedirections=No",
		"RequestUrl=*/authenticate*",
		LAST);

	web_reg_find("Search=Body",
		"Text=Welcome to PV Admin",
		LAST);

	web_submit_data("authenticate", 
		"Action={PV_Admin_URL}/login/authenticate", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={PV_Admin_URL}/external", 
		"Snapshot=t12.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=username", "Value={UserName}", ENDITEM, 
		"Name=password", "Value={Password}", ENDITEM, 
		"Name=callBackUrl", "Value=/", ENDITEM, 
		LAST);

	web_concurrent_start(NULL);

	web_url("application-3d87bac6ca7e570033e3b49e320180b2.css",
		"URL={PV_Admin_URL}/assets/application-3d87bac6ca7e570033e3b49e320180b2.css",
		"Resource=1",
		"RecContentType=text/css",
		"Referer={PV_Admin_URL}/?token={TokenId}",
		"Snapshot=t13.inf",
		LAST);

	web_url("jquery-2.2.4-f3b292379cbb03d9a68dc04fb0ac6bf5.js",
		"URL={PV_Admin_URL}/assets/vendorUi/jquery/jquery-2.2.4-f3b292379cbb03d9a68dc04fb0ac6bf5.js",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer={PV_Admin_URL}/?token={TokenId}",
		"Snapshot=t14.inf",
		LAST);

	web_url("application-73702747dcb4dc1831955be89087898f.js",
		"URL={PV_Admin_URL}/assets/application-73702747dcb4dc1831955be89087898f.js",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer={PV_Admin_URL}/?token={TokenId}",
		"Snapshot=t15.inf",
		LAST);

	web_url("UIConstants-e05f20031f3c986ffd86b552402112e0.js",
		"URL={PV_Admin_URL}/assets/UIConstants-e05f20031f3c986ffd86b552402112e0.js",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer={PV_Admin_URL}/?token={TokenId}",
		"Snapshot=t16.inf",
		LAST);

	web_url("change-theme-d6b58272d1305acd108c19d477017de0.js",
		"URL={PV_Admin_URL}/assets/common/change-theme-d6b58272d1305acd108c19d477017de0.js",
		"Resource=1",
		"RecContentType=application/javascript",
		"Referer={PV_Admin_URL}/?token={TokenId}",
		"Snapshot=t17.inf",
		LAST);

//	web_concurrent_end(NULL);
//
//	web_add_auto_header("Accept", 
//		"*/*");
//
//	web_add_auto_header("X-Requested-With", 
//		"XMLHttpRequest");

	web_url("loadTheme",
		"URL={PV_Admin_URL}/preference/loadTheme",
		"Resource=0",
		"RecContentType=application/json",
		"Referer={PV_Admin_URL}/?token={TokenId}",
		"Snapshot=t18.inf",
		"Mode=HTTP",
		LAST);

//	web_revert_auto_header("Accept");
//
//	web_add_header("Accept", 
//		"application/json, text/javascript, */*; q=0.01");

	web_url("en.json",
		"URL={PV_Admin_URL}/assets/i18n/en.json",
		"Resource=0",
		"RecContentType=application/json",
		"Referer={PV_Admin_URL}/?token={TokenId}",
		"Snapshot=t19.inf",
		"Mode=HTTP",
		LAST);

//	web_add_header("Origin", 
//		"{PV_Admin_URL}");
//
//	web_concurrent_start(NULL);

	web_url("OpenSans-Regular-cffb686d7d2f4682df8342bd4d276e09.woff2", 
		"URL={PV_Admin_URL}/assets/OpenSans-Regular-cffb686d7d2f4682df8342bd4d276e09.woff2?v=1.1.0", 
		"Resource=1", 
		"Referer={PV_Admin_URL}/assets/application-3d87bac6ca7e570033e3b49e320180b2.css", 
		"Snapshot=t20.inf", 
		LAST);

//	web_add_header("Origin", 
//		"{PV_Admin_URL}");

	web_url("fontawesome-webfont-af7ae505a9eed503f8b8e6982036873e.woff2", 
		"URL={PV_Admin_URL}/assets/fontawesome-webfont-af7ae505a9eed503f8b8e6982036873e.woff2?v=4.7.0", 
		"Resource=1", 
		"Referer={PV_Admin_URL}/assets/application-3d87bac6ca7e570033e3b49e320180b2.css", 
		"Snapshot=t21.inf", 
		LAST);

//	web_add_header("Origin", 
//		"{PV_Admin_URL}");

	web_url("materialdesignicons-webfont-af3f6dbe172a9c1aba77366a2ff630d1.woff2", 
		"URL={PV_Admin_URL}/assets/materialdesignicons-webfont-af3f6dbe172a9c1aba77366a2ff630d1.woff2?v=2.1.99", 
		"Resource=1", 
		"Referer={PV_Admin_URL}/assets/application-3d87bac6ca7e570033e3b49e320180b2.css", 
		"Snapshot=t22.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_revert_auto_header("Accept-Language");

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("Accept-Encoding", 
		"gzip, deflate, br");

	web_add_header("Sec-Fetch-Dest", 
		"empty");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Site", 
		"none");
	

	
	lr_end_transaction("FollowUp_02_Login",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("FollowUp_03_NavigateToPVIntake");

	web_add_header("Accept", 
		"text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9");

	web_add_auto_header("Accept-Language", 
		"en-US,en;q=0.9");

	web_add_auto_header("Accept-Encoding", 
		"gzip, deflate");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

/*Correlation comment - Do not change!  Original value='d004e878-3441-46b8-ac21-95b92c8ca98f' Name ='TokenId2' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=TokenId2",
		"LB= content=\"",
		"RB=\"/>\n        ",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/10.100.22.243:8081/*",
		LAST);

	web_reg_find("Search=Body",
		"Text=PV Intake",
		LAST);

	web_url("10.100.22.243:8081",
		"URL={PVI_URL}/",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={PV_Admin_URL}/?token={TokenId}",
		"Snapshot=t24.inf",
		"Mode=HTTP",
		LAST);

	web_add_header("Accept", 
		"text/css,*/*;q=0.1");

	web_concurrent_start(NULL);

	web_url("dashboard-manifest-b8c4a5998dad68d4595e4d0aa8d50016.css", 
		"URL={PVI_URL}/assets/app/dashboard/dashboard-manifest-b8c4a5998dad68d4595e4d0aa8d50016.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer={PVI_URL}/", 
		"Snapshot=t25.inf", 
		LAST);

//	web_add_header("Accept", 
//		"*/*");

	web_url("UIConstants-ee3587ab40d47b8bed173814ecf5a0be.js", 
		"URL={PVI_URL}/assets/UIConstants-ee3587ab40d47b8bed173814ecf5a0be.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={PVI_URL}/", 
		"Snapshot=t26.inf", 
		LAST);

//	web_add_header("Accept", 
//		"*/*");

	web_url("jquery-2.2.4-e72e6e97da5fd952079c33c415741fc6.js", 
		"URL={PVI_URL}/assets/vendorUi/jquery/jquery-2.2.4-e72e6e97da5fd952079c33c415741fc6.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={PVI_URL}/", 
		"Snapshot=t27.inf", 
		LAST);

//	web_add_header("Accept", 
//		"text/css,*/*;q=0.1");

	web_url("application-13a1ddae267b7b6a32d12cfb1ac98e43.css", 
		"URL={PVI_URL}/assets/application-13a1ddae267b7b6a32d12cfb1ac98e43.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer={PVI_URL}/", 
		"Snapshot=t28.inf", 
		LAST);

//	web_add_header("Accept", 
//		"*/*");

	web_url("change-theme-6ebd5f05979bc64dfe2d6f10b3e3b3db.js", 
		"URL={PVI_URL}/assets/common/change-theme-6ebd5f05979bc64dfe2d6f10b3e3b3db.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={PVI_URL}/", 
		"Snapshot=t29.inf", 
		LAST);

//	
//
//	web_add_auto_header("Accept", 
//		"*/*");
//
//	web_add_header("X-Requested-With", 
//		"XMLHttpRequest");

	web_url("loadTheme_2", 
		"URL={PVI_URL}/preference/loadTheme", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/", 
		"Snapshot=t30.inf", 
		"Mode=HTTP", 
		LAST);

//	web_add_header("Origin", 
//		"{PVI_URL}");

	web_url("OpenSans-Regular-cffb686d7d2f4682df8342bd4d276e09.woff2_2", 
		"URL={PVI_URL}/assets/OpenSans-Regular-cffb686d7d2f4682df8342bd4d276e09.woff2?v=1.1.0", 
		"Resource=1", 
		"Referer={PVI_URL}/assets/application-13a1ddae267b7b6a32d12cfb1ac98e43.css", 
		"Snapshot=t31.inf", 
		LAST);

	web_url("dashboard-manifest-10f1ed9d89cf396671bd4e3042b74253.js", 
		"URL={PVI_URL}/assets/app/dashboard/dashboard-manifest-10f1ed9d89cf396671bd4e3042b74253.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={PVI_URL}/", 
		"Snapshot=t32.inf", 
		LAST);

	web_url("application-a0469687a4859320633b35ed9c5374ee.js", 
		"URL={PVI_URL}/assets/application-a0469687a4859320633b35ed9c5374ee.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={PVI_URL}/", 
		"Snapshot=t33.inf", 
		LAST);

//	web_add_header("Origin", 
//		"{PVI_URL}");

	web_url("fontawesome-webfont-af7ae505a9eed503f8b8e6982036873e.woff2_2", 
		"URL={PVI_URL}/assets/fontawesome-webfont-af7ae505a9eed503f8b8e6982036873e.woff2?v=4.7.0", 
		"Resource=1", 
		"Referer={PVI_URL}/assets/application-13a1ddae267b7b6a32d12cfb1ac98e43.css", 
		"Snapshot=t34.inf", 
		LAST);

//	web_add_auto_header("Accept", 
//		"application/json, text/javascript, */*; q=0.01");
//
//	web_add_header("X-Requested-With", 
//		"XMLHttpRequest");

	web_url("appConfig", 
		"URL={PVI_URL}/config/appConfig", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/", 
		"Snapshot=t35.inf", 
		"Mode=HTTP", 
		LAST);

//	web_add_auto_header("Accept", 
//		"*/*");

	web_url("attachmentViewer-manifest-b347c0c37643c7b9e173f4b09adae617.js", 
		"URL={PVI_URL}/assets/vendor/attachmentViewer-manifest-b347c0c37643c7b9e173f4b09adae617.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={PVI_URL}/", 
		"Snapshot=t36.inf", 
		LAST);

//	web_add_auto_header("X-Requested-With", 
//		"XMLHttpRequest");

	web_url("loadAllState", 
		"URL={PVI_URL}/user/loadAllState?pageType=&section=", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/", 
		"Snapshot=t37.inf", 
		"Mode=HTTP", 
		LAST);

//	web_add_header("Origin", 
//		"{PVI_URL}");

	web_url("materialdesignicons-webfont-af3f6dbe172a9c1aba77366a2ff630d1.woff2_2", 
		"URL={PVI_URL}/assets/materialdesignicons-webfont-af3f6dbe172a9c1aba77366a2ff630d1.woff2?v=2.1.99", 
		"Resource=1", 
		"Referer={PVI_URL}/assets/application-13a1ddae267b7b6a32d12cfb1ac98e43.css", 
		"Snapshot=t38.inf", 
		LAST);

	web_url("referenceData", 
		"URL={PVI_URL}/task/referenceData?_=1598531772258", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/", 
		"Snapshot=t39.inf", 
		"Mode=HTTP", 
		LAST);

//	web_add_auto_header("Accept", 
//		"application/json, text/javascript, */*; q=0.01");

	web_url("loadServerTime", 
		"URL={PVI_URL}/config/loadServerTime?_=1598531772259", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/", 
		"Snapshot=t40.inf", 
		"Mode=HTTP", 
		LAST);

//	web_add_auto_header("Accept", 
//		"*/*");

	web_url("personalStats", 
		"URL={PVI_URL}/dashboard/personalStats?_=1598531772260", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/", 
		"Snapshot=t41.inf", 
		"Mode=HTTP", 
		LAST);

//	web_add_header("Origin", 
//		"{PVI_URL}");

	web_url("glyphicons-halflings-regular-448c34a56d699c29117adc64c43affeb.woff2", 
		"URL={PVI_URL}/assets/glyphicons-halflings-regular-448c34a56d699c29117adc64c43affeb.woff2", 
		"Resource=1", 
		"Referer={PVI_URL}/assets/application-13a1ddae267b7b6a32d12cfb1ac98e43.css", 
		"Snapshot=t42.inf", 
		LAST);

	web_url("predefinedSearch.json", 
		"URL={PVI_URL}/assets/vendor/documentViewerJson/predefinedSearch.json?_=1598531772264", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/", 
		"Snapshot=t43.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("2", 
		"URL={PVI_URL}/case/rest/list_columns/2?_=1598531772261", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/", 
		"Snapshot=t44.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("1", 
		"URL={PVI_URL}/case/rest/list_columns/1?_=1598531772262", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/", 
		"Snapshot=t45.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("en-US.json", 
		"URL={PVI_URL}/assets/vendor/documentViewerJson/en-US.json?_=1598531772263", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/", 
		"Snapshot=t46.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("redactionReason.json", 
		"URL={PVI_URL}/assets/vendor/documentViewerJson/redactionReason.json?_=1598531772265", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/", 
		"Snapshot=t47.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("commentTemplate.html", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/commentTemplate.html?_=1598531772266", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/", 
		"Snapshot=t48.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("copyOverlayTemplate.html", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/copyOverlayTemplate.html?_=1598531772268", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/", 
		"Snapshot=t49.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("hyperlinkMenuTemplate.html", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/hyperlinkMenuTemplate.html?_=1598531772271", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/", 
		"Snapshot=t50.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("downloadOverlayTemplate.html", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/downloadOverlayTemplate.html?_=1598531772269", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/", 
		"Snapshot=t51.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("esignOverlayTemplate.html", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/esignOverlayTemplate.html?_=1598531772270", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/", 
		"Snapshot=t52.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("contextMenuTemplate.html", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/contextMenuTemplate.html?_=1598531772267", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/", 
		"Snapshot=t53.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("imageStampOverlayTemplate.html", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/imageStampOverlayTemplate.html?_=1598531772272", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/", 
		"Snapshot=t54.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("overwriteOverlayTemplate.html", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/overwriteOverlayTemplate.html?_=1598531772273", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/", 
		"Snapshot=t55.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_end(NULL);
	
	web_add_header("Origin", 
		"{PVI_URL}");

	web_add_header("X-CSRF-TOKEN",
		"{TokenId2}");

	web_submit_data("loadState", 
		"Action={PVI_URL}/user/loadState", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/", 
		"Snapshot=t56.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=pageType", "Value=case_list_form", ENDITEM, 
		"Name=section", "Value=DataTable", ENDITEM, 
		LAST);

	web_url("printOverlayTemplate.html", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/printOverlayTemplate.html?_=1598531772275", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/", 
		"Snapshot=t57.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("pageRedactionOverlayTemplate.html", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/pageRedactionOverlayTemplate.html?_=1598531772274", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/", 
		"Snapshot=t58.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("redactionReasonTemplate.html", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/redactionReasonTemplate.html?_=1598531772277", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/", 
		"Snapshot=t59.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("printTemplate.html", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/printTemplate.html?_=1598531772276", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/", 
		"Snapshot=t60.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("unsavedChangesOverlayTemplate.html", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/unsavedChangesOverlayTemplate.html?_=1598531772278", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/", 
		"Snapshot=t61.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("viewerTemplate.html", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/viewerTemplate.html?_=1598531772279", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/", 
		"Snapshot=t62.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_auto_header("Accept", 
		"application/json, text/javascript, */*; q=0.01");

	web_add_auto_header("Origin", 
		"{PVI_URL}");

	web_add_auto_header("X-CSRF-TOKEN",
		"{TokenId2}");

	web_submit_data("updateWidget", 
		"Action={PVI_URL}/dashboard/updateWidget", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/", 
		"Snapshot=t63.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=items", "Value=[\n    {\n        \"id\": \"417\",\n        \"x\": 0,\n        \"y\": 0,\n        \"width\": 3,\n        \"height\": 3\n    },\n    {\n        \"id\": \"418\",\n        \"x\": 3,\n        \"y\": 0,\n        \"width\": 9,\n        \"height\": 3\n    },\n    {\n        \"id\": \"419\",\n        \"x\": 0,\n        \"y\": 3,\n        \"width\": 12,\n        \"height\": 7\n    },\n    {\n        \"id\": \"420\",\n        \"x\": 0,\n        \"y\": 10,\n        \"width\": 12,\n       "
		" \"height\": 7\n    }\n]", ENDITEM, 
		LAST);

	web_submit_data("updateWidget_2", 
		"Action={PVI_URL}/dashboard/updateWidget", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/", 
		"Snapshot=t64.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=items", "Value=[\n    {\n        \"id\": \"417\",\n        \"x\": 0,\n        \"y\": 0,\n        \"width\": 3,\n        \"height\": 3\n    },\n    {\n        \"id\": \"418\",\n        \"x\": 3,\n        \"y\": 0,\n        \"width\": 9,\n        \"height\": 3\n    },\n    {\n        \"id\": \"419\",\n        \"x\": 0,\n        \"y\": 3,\n        \"width\": 12,\n        \"height\": 7\n    },\n    {\n        \"id\": \"420\",\n        \"x\": 0,\n        \"y\": 10,\n        \"width\": 12,\n       "
		" \"height\": 7\n    }\n]", ENDITEM, 
		LAST);

	web_add_auto_header("Accept", 
		"*/*");

	web_submit_data("loadState_2", 
		"Action={PVI_URL}/user/loadState", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/", 
		"Snapshot=t65.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=pageType", "Value=intake_queue_form", ENDITEM, 
		"Name=section", "Value=DataTable", ENDITEM, 
		LAST);

	web_submit_data("1_2", 
		"Action={PVI_URL}/case/rest/list/1", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/", 
		"Snapshot=t66.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=draw", "Value=2", ENDITEM, 
		"Name=columns[0][data]", "Value=selected", ENDITEM, 
		"Name=columns[0][name]", "Value=selected", ENDITEM, 
		"Name=columns[0][searchable]", "Value=true", ENDITEM, 
		"Name=columns[0][orderable]", "Value=false", ENDITEM, 
		"Name=columns[0][search][value]", "Value=", ENDITEM, 
		"Name=columns[0][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[1][data]", "Value=intakeCaseNumber", ENDITEM, 
		"Name=columns[1][name]", "Value=intakeCaseNumber", ENDITEM, 
		"Name=columns[1][searchable]", "Value=true", ENDITEM, 
		"Name=columns[1][orderable]", "Value=true", ENDITEM, 
		"Name=columns[1][search][value]", "Value=", ENDITEM, 
		"Name=columns[1][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[2][data]", "Value=caseVersion", ENDITEM, 
		"Name=columns[2][name]", "Value=caseVersion", ENDITEM, 
		"Name=columns[2][searchable]", "Value=true", ENDITEM, 
		"Name=columns[2][orderable]", "Value=true", ENDITEM, 
		"Name=columns[2][search][value]", "Value=", ENDITEM, 
		"Name=columns[2][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[3][data]", "Value=firstReceiptDateString", ENDITEM, 
		"Name=columns[3][name]", "Value=firstReceiptDate", ENDITEM, 
		"Name=columns[3][searchable]", "Value=true", ENDITEM, 
		"Name=columns[3][orderable]", "Value=true", ENDITEM, 
		"Name=columns[3][search][value]", "Value=", ENDITEM, 
		"Name=columns[3][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[4][data]", "Value=mostRecentReceiptDateString", ENDITEM, 
		"Name=columns[4][name]", "Value=mostRecentReceiptDate", ENDITEM, 
		"Name=columns[4][searchable]", "Value=true", ENDITEM, 
		"Name=columns[4][orderable]", "Value=true", ENDITEM, 
		"Name=columns[4][search][value]", "Value=", ENDITEM, 
		"Name=columns[4][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[5][data]", "Value=sourceType", ENDITEM, 
		"Name=columns[5][name]", "Value=sourceType.type", ENDITEM, 
		"Name=columns[5][searchable]", "Value=true", ENDITEM, 
		"Name=columns[5][orderable]", "Value=true", ENDITEM, 
		"Name=columns[5][search][value]", "Value=", ENDITEM, 
		"Name=columns[5][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[6][data]", "Value=products", ENDITEM, 
		"Name=columns[6][name]", "Value=products.name", ENDITEM, 
		"Name=columns[6][searchable]", "Value=true", ENDITEM, 
		"Name=columns[6][orderable]", "Value=false", ENDITEM, 
		"Name=columns[6][search][value]", "Value=", ENDITEM, 
		"Name=columns[6][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[7][data]", "Value=events", ENDITEM, 
		"Name=columns[7][name]", "Value=events.eventName", ENDITEM, 
		"Name=columns[7][searchable]", "Value=true", ENDITEM, 
		"Name=columns[7][orderable]", "Value=false", ENDITEM, 
		"Name=columns[7][search][value]", "Value=", ENDITEM, 
		"Name=columns[7][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[8][data]", "Value=caseSeriousness", ENDITEM, 
		"Name=columns[8][name]", "Value=caseSeriousness.category", ENDITEM, 
		"Name=columns[8][searchable]", "Value=true", ENDITEM, 
		"Name=columns[8][orderable]", "Value=true", ENDITEM, 
		"Name=columns[8][search][value]", "Value=", ENDITEM, 
		"Name=columns[8][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[9][data]", "Value=dueDateString", ENDITEM, 
		"Name=columns[9][name]", "Value=dueDate", ENDITEM, 
		"Name=columns[9][searchable]", "Value=true", ENDITEM, 
		"Name=columns[9][orderable]", "Value=true", ENDITEM, 
		"Name=columns[9][search][value]", "Value=", ENDITEM, 
		"Name=columns[9][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[10][data]", "Value=caseState", ENDITEM, 
		"Name=columns[10][name]", "Value=caseState", ENDITEM, 
		"Name=columns[10][searchable]", "Value=true", ENDITEM, 
		"Name=columns[10][orderable]", "Value=true", ENDITEM, 
		"Name=columns[10][search][value]", "Value=", ENDITEM, 
		"Name=columns[10][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[11][data]", "Value=assignedToUsername", ENDITEM, 
		"Name=columns[11][name]", "Value=assignedToUsername", ENDITEM, 
		"Name=columns[11][searchable]", "Value=true", ENDITEM, 
		"Name=columns[11][orderable]", "Value=true", ENDITEM, 
		"Name=columns[11][search][value]", "Value=", ENDITEM, 
		"Name=columns[11][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[12][data]", "Value=reporterQualification", ENDITEM, 
		"Name=columns[12][name]", "Value=reporters.qualificationValue", ENDITEM, 
		"Name=columns[12][searchable]", "Value=true", ENDITEM, 
		"Name=columns[12][orderable]", "Value=true", ENDITEM, 
		"Name=columns[12][search][value]", "Value=", ENDITEM, 
		"Name=columns[12][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[13][data]", "Value=priority", ENDITEM, 
		"Name=columns[13][name]", "Value=priority.value", ENDITEM, 
		"Name=columns[13][searchable]", "Value=true", ENDITEM, 
		"Name=columns[13][orderable]", "Value=true", ENDITEM, 
		"Name=columns[13][search][value]", "Value=", ENDITEM, 
		"Name=columns[13][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[14][data]", "Value=attachments", ENDITEM, 
		"Name=columns[14][name]", "Value=attachments.name", ENDITEM, 
		"Name=columns[14][searchable]", "Value=true", ENDITEM, 
		"Name=columns[14][orderable]", "Value=false", ENDITEM, 
		"Name=columns[14][search][value]", "Value=", ENDITEM, 
		"Name=columns[14][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[15][data]", "Value=isRelated", ENDITEM, 
		"Name=columns[15][name]", "Value=isRelated", ENDITEM, 
		"Name=columns[15][searchable]", "Value=true", ENDITEM, 
		"Name=columns[15][orderable]", "Value=true", ENDITEM, 
		"Name=columns[15][search][value]", "Value=", ENDITEM, 
		"Name=columns[15][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[16][data]", "Value=safetyCaseNumber", ENDITEM, 
		"Name=columns[16][name]", "Value=safetyCaseNumber", ENDITEM, 
		"Name=columns[16][searchable]", "Value=true", ENDITEM, 
		"Name=columns[16][orderable]", "Value=true", ENDITEM, 
		"Name=columns[16][search][value]", "Value=", ENDITEM, 
		"Name=columns[16][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[17][data]", "Value=reportType", ENDITEM, 
		"Name=columns[17][name]", "Value=reportType", ENDITEM, 
		"Name=columns[17][searchable]", "Value=true", ENDITEM, 
		"Name=columns[17][orderable]", "Value=true", ENDITEM, 
		"Name=columns[17][search][value]", "Value=", ENDITEM, 
		"Name=columns[17][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[18][data]", "Value=patientAge", ENDITEM, 
		"Name=columns[18][name]", "Value=patientAge", ENDITEM, 
		"Name=columns[18][searchable]", "Value=true", ENDITEM, 
		"Name=columns[18][orderable]", "Value=false", ENDITEM, 
		"Name=columns[18][search][value]", "Value=", ENDITEM, 
		"Name=columns[18][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[19][data]", "Value=gender", ENDITEM, 
		"Name=columns[19][name]", "Value=gender.value", ENDITEM, 
		"Name=columns[19][searchable]", "Value=true", ENDITEM, 
		"Name=columns[19][orderable]", "Value=true", ENDITEM, 
		"Name=columns[19][search][value]", "Value=", ENDITEM, 
		"Name=columns[19][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[20][data]", "Value=destination", ENDITEM, 
		"Name=columns[20][name]", "Value=icsr.destination", ENDITEM, 
		"Name=columns[20][searchable]", "Value=true", ENDITEM, 
		"Name=columns[20][orderable]", "Value=true", ENDITEM, 
		"Name=columns[20][search][value]", "Value=", ENDITEM, 
		"Name=columns[20][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[21][data]", "Value=reportDueDateString", ENDITEM, 
		"Name=columns[21][name]", "Value=icsr.dueDate", ENDITEM, 
		"Name=columns[21][searchable]", "Value=true", ENDITEM, 
		"Name=columns[21][orderable]", "Value=true", ENDITEM, 
		"Name=columns[21][search][value]", "Value=", ENDITEM, 
		"Name=columns[21][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[22][data]", "Value=reporterComments", ENDITEM, 
		"Name=columns[22][name]", "Value=reporterComments", ENDITEM, 
		"Name=columns[22][searchable]", "Value=true", ENDITEM, 
		"Name=columns[22][orderable]", "Value=false", ENDITEM, 
		"Name=columns[22][search][value]", "Value=", ENDITEM, 
		"Name=columns[22][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[23][data]", "Value=reporters", ENDITEM, 
		"Name=columns[23][name]", "Value=reporters.name", ENDITEM, 
		"Name=columns[23][searchable]", "Value=true", ENDITEM, 
		"Name=columns[23][orderable]", "Value=true", ENDITEM, 
		"Name=columns[23][search][value]", "Value=", ENDITEM, 
		"Name=columns[23][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[24][data]", "Value=senderType", ENDITEM, 
		"Name=columns[24][name]", "Value=senderType.value", ENDITEM, 
		"Name=columns[24][searchable]", "Value=true", ENDITEM, 
		"Name=columns[24][orderable]", "Value=true", ENDITEM, 
		"Name=columns[24][search][value]", "Value=", ENDITEM, 
		"Name=columns[24][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[25][data]", "Value=senderName", ENDITEM, 
		"Name=columns[25][name]", "Value=senderName", ENDITEM, 
		"Name=columns[25][searchable]", "Value=true", ENDITEM, 
		"Name=columns[25][orderable]", "Value=true", ENDITEM, 
		"Name=columns[25][search][value]", "Value=", ENDITEM, 
		"Name=columns[25][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[26][data]", "Value=eventCountry", ENDITEM, 
		"Name=columns[26][name]", "Value=eventCountry.name", ENDITEM, 
		"Name=columns[26][searchable]", "Value=true", ENDITEM, 
		"Name=columns[26][orderable]", "Value=true", ENDITEM, 
		"Name=columns[26][search][value]", "Value=", ENDITEM, 
		"Name=columns[26][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[27][data]", "Value=reportVersion", ENDITEM, 
		"Name=columns[27][name]", "Value=icsr.reportVersion", ENDITEM, 
		"Name=columns[27][searchable]", "Value=true", ENDITEM, 
		"Name=columns[27][orderable]", "Value=true", ENDITEM, 
		"Name=columns[27][search][value]", "Value=", ENDITEM, 
		"Name=columns[27][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[28][data]", "Value=icsr", ENDITEM, 
		"Name=columns[28][name]", "Value=icsr.transmissionStatus", ENDITEM, 
		"Name=columns[28][searchable]", "Value=true", ENDITEM, 
		"Name=columns[28][orderable]", "Value=true", ENDITEM, 
		"Name=columns[28][search][value]", "Value=", ENDITEM, 
		"Name=columns[28][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[29][data]", "Value=stateTimestampString", ENDITEM, 
		"Name=columns[29][name]", "Value=icsr.stateTimestamp", ENDITEM, 
		"Name=columns[29][searchable]", "Value=true", ENDITEM, 
		"Name=columns[29][orderable]", "Value=true", ENDITEM, 
		"Name=columns[29][search][value]", "Value=", ENDITEM, 
		"Name=columns[29][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[30][data]", "Value=reportMessage", ENDITEM, 
		"Name=columns[30][name]", "Value=icsr.reportMessage", ENDITEM, 
		"Name=columns[30][searchable]", "Value=true", ENDITEM, 
		"Name=columns[30][orderable]", "Value=false", ENDITEM, 
		"Name=columns[30][search][value]", "Value=", ENDITEM, 
		"Name=columns[30][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[31][data]", "Value=eventName", ENDITEM, 
		"Name=columns[31][name]", "Value=eventName", ENDITEM, 
		"Name=columns[31][searchable]", "Value=true", ENDITEM, 
		"Name=columns[31][orderable]", "Value=true", ENDITEM, 
		"Name=columns[31][search][value]", "Value=", ENDITEM, 
		"Name=columns[31][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[32][data]", "Value=eventStartDate", ENDITEM, 
		"Name=columns[32][name]", "Value=eventStartDate", ENDITEM, 
		"Name=columns[32][searchable]", "Value=true", ENDITEM, 
		"Name=columns[32][orderable]", "Value=true", ENDITEM, 
		"Name=columns[32][search][value]", "Value=", ENDITEM, 
		"Name=columns[32][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[33][data]", "Value=outcome", ENDITEM, 
		"Name=columns[33][name]", "Value=outcome.value", ENDITEM, 
		"Name=columns[33][searchable]", "Value=true", ENDITEM, 
		"Name=columns[33][orderable]", "Value=true", ENDITEM, 
		"Name=columns[33][search][value]", "Value=", ENDITEM, 
		"Name=columns[33][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[34][data]", "Value=reporterCountry", ENDITEM, 
		"Name=columns[34][name]", "Value=reporters.countryName", ENDITEM, 
		"Name=columns[34][searchable]", "Value=true", ENDITEM, 
		"Name=columns[34][orderable]", "Value=true", ENDITEM, 
		"Name=columns[34][search][value]", "Value=", ENDITEM, 
		"Name=columns[34][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[35][data]", "Value=relatednessString", ENDITEM, 
		"Name=columns[35][name]", "Value=relatednessString", ENDITEM, 
		"Name=columns[35][searchable]", "Value=true", ENDITEM, 
		"Name=columns[35][orderable]", "Value=true", ENDITEM, 
		"Name=columns[35][search][value]", "Value=", ENDITEM, 
		"Name=columns[35][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[36][data]", "Value=categories", ENDITEM, 
		"Name=columns[36][name]", "Value=categories.value", ENDITEM, 
		"Name=columns[36][searchable]", "Value=true", ENDITEM, 
		"Name=columns[36][orderable]", "Value=false", ENDITEM, 
		"Name=columns[36][search][value]", "Value=", ENDITEM, 
		"Name=columns[36][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[37][data]", "Value=productName", ENDITEM, 
		"Name=columns[37][name]", "Value=productName", ENDITEM, 
		"Name=columns[37][searchable]", "Value=true", ENDITEM, 
		"Name=columns[37][orderable]", "Value=true", ENDITEM, 
		"Name=columns[37][search][value]", "Value=", ENDITEM, 
		"Name=columns[37][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[38][data]", "Value=substances", ENDITEM, 
		"Name=columns[38][name]", "Value=substances.nameValue", ENDITEM, 
		"Name=columns[38][searchable]", "Value=true", ENDITEM, 
		"Name=columns[38][orderable]", "Value=false", ENDITEM, 
		"Name=columns[38][search][value]", "Value=", ENDITEM, 
		"Name=columns[38][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[39][data]", "Value=studyNumber", ENDITEM, 
		"Name=columns[39][name]", "Value=studyNumber", ENDITEM, 
		"Name=columns[39][searchable]", "Value=true", ENDITEM, 
		"Name=columns[39][orderable]", "Value=true", ENDITEM, 
		"Name=columns[39][search][value]", "Value=", ENDITEM, 
		"Name=columns[39][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[40][data]", "Value=versionType", ENDITEM, 
		"Name=columns[40][name]", "Value=versionType.value", ENDITEM, 
		"Name=columns[40][searchable]", "Value=true", ENDITEM, 
		"Name=columns[40][orderable]", "Value=true", ENDITEM, 
		"Name=columns[40][search][value]", "Value=", ENDITEM, 
		"Name=columns[40][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[41][data]", "Value=receiptDateString", ENDITEM, 
		"Name=columns[41][name]", "Value=receiptDate", ENDITEM, 
		"Name=columns[41][searchable]", "Value=true", ENDITEM, 
		"Name=columns[41][orderable]", "Value=false", ENDITEM, 
		"Name=columns[41][search][value]", "Value=", ENDITEM, 
		"Name=columns[41][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[42][data]", "Value=onsetDate", ENDITEM, 
		"Name=columns[42][name]", "Value=onsetDate", ENDITEM, 
		"Name=columns[42][searchable]", "Value=true", ENDITEM, 
		"Name=columns[42][orderable]", "Value=true", ENDITEM, 
		"Name=columns[42][search][value]", "Value=", ENDITEM, 
		"Name=columns[42][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[43][data]", "Value=submissionDate", ENDITEM, 
		"Name=columns[43][name]", "Value=submissionDate", ENDITEM, 
		"Name=columns[43][searchable]", "Value=true", ENDITEM, 
		"Name=columns[43][orderable]", "Value=true", ENDITEM, 
		"Name=columns[43][search][value]", "Value=", ENDITEM, 
		"Name=columns[43][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[44][data]", "Value=dosageForm", ENDITEM, 
		"Name=columns[44][name]", "Value=dosageForm.value", ENDITEM, 
		"Name=columns[44][searchable]", "Value=true", ENDITEM, 
		"Name=columns[44][orderable]", "Value=true", ENDITEM, 
		"Name=columns[44][search][value]", "Value=", ENDITEM, 
		"Name=columns[44][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[45][data]", "Value=caseVersionType", ENDITEM, 
		"Name=columns[45][name]", "Value=caseVersionType", ENDITEM, 
		"Name=columns[45][searchable]", "Value=true", ENDITEM, 
		"Name=columns[45][orderable]", "Value=true", ENDITEM, 
		"Name=columns[45][search][value]", "Value=", ENDITEM, 
		"Name=columns[45][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[46][data]", "Value=icsrType", ENDITEM, 
		"Name=columns[46][name]", "Value=icsr.type", ENDITEM, 
		"Name=columns[46][searchable]", "Value=true", ENDITEM, 
		"Name=columns[46][orderable]", "Value=true", ENDITEM, 
		"Name=columns[46][search][value]", "Value=", ENDITEM, 
		"Name=columns[46][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[47][data]", "Value=studyType", ENDITEM, 
		"Name=columns[47][name]", "Value=studyType.value", ENDITEM, 
		"Name=columns[47][searchable]", "Value=true", ENDITEM, 
		"Name=columns[47][orderable]", "Value=true", ENDITEM, 
		"Name=columns[47][search][value]", "Value=", ENDITEM, 
		"Name=columns[47][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[48][data]", "Value=patientName", ENDITEM, 
		"Name=columns[48][name]", "Value=patientName", ENDITEM, 
		"Name=columns[48][searchable]", "Value=true", ENDITEM, 
		"Name=columns[48][orderable]", "Value=true", ENDITEM, 
		"Name=columns[48][search][value]", "Value=", ENDITEM, 
		"Name=columns[48][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[49][data]", "Value=seriousness", ENDITEM, 
		"Name=columns[49][name]", "Value=seriousnessString", ENDITEM, 
		"Name=columns[49][searchable]", "Value=true", ENDITEM, 
		"Name=columns[49][orderable]", "Value=false", ENDITEM, 
		"Name=columns[49][search][value]", "Value=", ENDITEM, 
		"Name=columns[49][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[50][data]", "Value=caseCountry", ENDITEM, 
		"Name=columns[50][name]", "Value=caseCountry.name", ENDITEM, 
		"Name=columns[50][searchable]", "Value=true", ENDITEM, 
		"Name=columns[50][orderable]", "Value=true", ENDITEM, 
		"Name=columns[50][search][value]", "Value=", ENDITEM, 
		"Name=columns[50][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[51][data]", "Value=allReferences", ENDITEM, 
		"Name=columns[51][name]", "Value=allReferences", ENDITEM, 
		"Name=columns[51][searchable]", "Value=true", ENDITEM, 
		"Name=columns[51][orderable]", "Value=false", ENDITEM, 
		"Name=columns[51][search][value]", "Value=", ENDITEM, 
		"Name=columns[51][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[52][data]", "Value=patientId", ENDITEM, 
		"Name=columns[52][name]", "Value=patientId", ENDITEM, 
		"Name=columns[52][searchable]", "Value=true", ENDITEM, 
		"Name=columns[52][orderable]", "Value=true", ENDITEM, 
		"Name=columns[52][search][value]", "Value=", ENDITEM, 
		"Name=columns[52][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[53][data]", "Value=dobString", ENDITEM, 
		"Name=columns[53][name]", "Value=dob", ENDITEM, 
		"Name=columns[53][searchable]", "Value=true", ENDITEM, 
		"Name=columns[53][orderable]", "Value=true", ENDITEM, 
		"Name=columns[53][search][value]", "Value=", ENDITEM, 
		"Name=columns[53][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[54][data]", "Value=matchScore", ENDITEM, 
		"Name=columns[54][name]", "Value=matchScore", ENDITEM, 
		"Name=columns[54][searchable]", "Value=true", ENDITEM, 
		"Name=columns[54][orderable]", "Value=true", ENDITEM, 
		"Name=columns[54][search][value]", "Value=", ENDITEM, 
		"Name=columns[54][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[55][data]", "Value=simpleSearch", ENDITEM, 
		"Name=columns[55][name]", "Value=simpleSearch", ENDITEM, 
		"Name=columns[55][searchable]", "Value=true", ENDITEM, 
		"Name=columns[55][orderable]", "Value=true", ENDITEM, 
		"Name=columns[55][search][value]", "Value={\"simpleSearch\":\"\",\"caseStateId\":\"2,3,4,6\",\"config\":\"{\\\"isOrOperation\\\": \\\"false\\\", \\\"sortWhileSearch\\\": \\\"false\\\", \\\"countSearchCriteria\\\": \\\"false\\\"}\",\"reportDistributionThreshold\":true,\"sourceDbId\":\"1\",\"firstReceiptDate\":\"{\\\"gte\\\":\\\"2019-08-29T00:00:00Z\\\",\\\"lte\\\":\\\"2020-08-27T23:59:59Z\\\"}\"}", ENDITEM, 
		"Name=columns[55][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[56][data]", "Value=dateRangeSearch", ENDITEM, 
		"Name=columns[56][name]", "Value=dateRangeSearch", ENDITEM, 
		"Name=columns[56][searchable]", "Value=true", ENDITEM, 
		"Name=columns[56][orderable]", "Value=true", ENDITEM, 
		"Name=columns[56][search][value]", "Value=", ENDITEM, 
		"Name=columns[56][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[57][data]", "Value=sourceDb", ENDITEM, 
		"Name=columns[57][name]", "Value=sourceDb", ENDITEM, 
		"Name=columns[57][searchable]", "Value=true", ENDITEM, 
		"Name=columns[57][orderable]", "Value=true", ENDITEM, 
		"Name=columns[57][search][value]", "Value=", ENDITEM, 
		"Name=columns[57][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[58][data]", "Value=safetyWFState", ENDITEM, 
		"Name=columns[58][name]", "Value=safetyWFState", ENDITEM, 
		"Name=columns[58][searchable]", "Value=true", ENDITEM, 
		"Name=columns[58][orderable]", "Value=true", ENDITEM, 
		"Name=columns[58][search][value]", "Value=", ENDITEM, 
		"Name=columns[58][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[59][data]", "Value=centralReceiptDateString", ENDITEM, 
		"Name=columns[59][name]", "Value=centralReceiptDate", ENDITEM, 
		"Name=columns[59][searchable]", "Value=true", ENDITEM, 
		"Name=columns[59][orderable]", "Value=true", ENDITEM, 
		"Name=columns[59][search][value]", "Value=", ENDITEM, 
		"Name=columns[59][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[60][data]", "Value=localSubmissionDateString", ENDITEM, 
		"Name=columns[60][name]", "Value=localSubmissionDate", ENDITEM, 
		"Name=columns[60][searchable]", "Value=true", ENDITEM, 
		"Name=columns[60][orderable]", "Value=true", ENDITEM, 
		"Name=columns[60][search][value]", "Value=", ENDITEM, 
		"Name=columns[60][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[61][data]", "Value=localSubmissionDueDateString", ENDITEM, 
		"Name=columns[61][name]", "Value=localSubmissionDueDate", ENDITEM, 
		"Name=columns[61][searchable]", "Value=true", ENDITEM, 
		"Name=columns[61][orderable]", "Value=true", ENDITEM, 
		"Name=columns[61][search][value]", "Value=", ENDITEM, 
		"Name=columns[61][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[62][data]", "Value=latestAssignmentComment", ENDITEM, 
		"Name=columns[62][name]", "Value=latestAssignmentComment", ENDITEM, 
		"Name=columns[62][searchable]", "Value=true", ENDITEM, 
		"Name=columns[62][orderable]", "Value=false", ENDITEM, 
		"Name=columns[62][search][value]", "Value=", ENDITEM, 
		"Name=columns[62][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[63][data]", "Value=vendor", ENDITEM, 
		"Name=columns[63][name]", "Value=vendor", ENDITEM, 
		"Name=columns[63][searchable]", "Value=true", ENDITEM, 
		"Name=columns[63][orderable]", "Value=true", ENDITEM, 
		"Name=columns[63][search][value]", "Value=", ENDITEM, 
		"Name=columns[63][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[64][data]", "Value=replacementRequired", ENDITEM, 
		"Name=columns[64][name]", "Value=replacementRequired", ENDITEM, 
		"Name=columns[64][searchable]", "Value=true", ENDITEM, 
		"Name=columns[64][orderable]", "Value=true", ENDITEM, 
		"Name=columns[64][search][value]", "Value=", ENDITEM, 
		"Name=columns[64][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[65][data]", "Value=caseCreatedDate", ENDITEM, 
		"Name=columns[65][name]", "Value=caseCreatedDate", ENDITEM, 
		"Name=columns[65][searchable]", "Value=true", ENDITEM, 
		"Name=columns[65][orderable]", "Value=true", ENDITEM, 
		"Name=columns[65][search][value]", "Value=", ENDITEM, 
		"Name=columns[65][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[66][data]", "Value=reporters", ENDITEM, 
		"Name=columns[66][name]", "Value=reporters.organization", ENDITEM, 
		"Name=columns[66][searchable]", "Value=true", ENDITEM, 
		"Name=columns[66][orderable]", "Value=true", ENDITEM, 
		"Name=columns[66][search][value]", "Value=", ENDITEM, 
		"Name=columns[66][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[67][data]", "Value=reporters", ENDITEM, 
		"Name=columns[67][name]", "Value=reporters.department", ENDITEM, 
		"Name=columns[67][searchable]", "Value=true", ENDITEM, 
		"Name=columns[67][orderable]", "Value=true", ENDITEM, 
		"Name=columns[67][search][value]", "Value=", ENDITEM, 
		"Name=columns[67][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[68][data]", "Value=reporters", ENDITEM, 
		"Name=columns[68][name]", "Value=reporters.address", ENDITEM, 
		"Name=columns[68][searchable]", "Value=true", ENDITEM, 
		"Name=columns[68][orderable]", "Value=true", ENDITEM, 
		"Name=columns[68][search][value]", "Value=", ENDITEM, 
		"Name=columns[68][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[69][data]", "Value=reporters", ENDITEM, 
		"Name=columns[69][name]", "Value=reporters.telephone", ENDITEM, 
		"Name=columns[69][searchable]", "Value=true", ENDITEM, 
		"Name=columns[69][orderable]", "Value=true", ENDITEM, 
		"Name=columns[69][search][value]", "Value=", ENDITEM, 
		"Name=columns[69][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[70][data]", "Value=reporters", ENDITEM, 
		"Name=columns[70][name]", "Value=reporters.faxNumber", ENDITEM, 
		"Name=columns[70][searchable]", "Value=true", ENDITEM, 
		"Name=columns[70][orderable]", "Value=true", ENDITEM, 
		"Name=columns[70][search][value]", "Value=", ENDITEM, 
		"Name=columns[70][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[71][data]", "Value=reporters", ENDITEM, 
		"Name=columns[71][name]", "Value=reporters.email", ENDITEM, 
		"Name=columns[71][searchable]", "Value=true", ENDITEM, 
		"Name=columns[71][orderable]", "Value=true", ENDITEM, 
		"Name=columns[71][search][value]", "Value=", ENDITEM, 
		"Name=columns[71][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[72][data]", "Value=pqcCaseNumber", ENDITEM, 
		"Name=columns[72][name]", "Value=pqcCaseNumber", ENDITEM, 
		"Name=columns[72][searchable]", "Value=true", ENDITEM, 
		"Name=columns[72][orderable]", "Value=true", ENDITEM, 
		"Name=columns[72][search][value]", "Value=", ENDITEM, 
		"Name=columns[72][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[73][data]", "Value=returnRequired", ENDITEM, 
		"Name=columns[73][name]", "Value=returnRequired", ENDITEM, 
		"Name=columns[73][searchable]", "Value=true", ENDITEM, 
		"Name=columns[73][orderable]", "Value=true", ENDITEM, 
		"Name=columns[73][search][value]", "Value=", ENDITEM, 
		"Name=columns[73][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[74][data]", "Value=refundRequested", ENDITEM, 
		"Name=columns[74][name]", "Value=refundRequested", ENDITEM, 
		"Name=columns[74][searchable]", "Value=true", ENDITEM, 
		"Name=columns[74][orderable]", "Value=true", ENDITEM, 
		"Name=columns[74][search][value]", "Value=", ENDITEM, 
		"Name=columns[74][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[75][data]", "Value=reporters", ENDITEM, 
		"Name=columns[75][name]", "Value=reporters.contactTypes.value", ENDITEM, 
		"Name=columns[75][searchable]", "Value=true", ENDITEM, 
		"Name=columns[75][orderable]", "Value=false", ENDITEM, 
		"Name=columns[75][search][value]", "Value=", ENDITEM, 
		"Name=columns[75][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[76][data]", "Value=action", ENDITEM, 
		"Name=columns[76][name]", "Value=", ENDITEM, 
		"Name=columns[76][searchable]", "Value=true", ENDITEM, 
		"Name=columns[76][orderable]", "Value=false", ENDITEM, 
		"Name=columns[76][search][value]", "Value=", ENDITEM, 
		"Name=columns[76][search][regex]", "Value=false", ENDITEM, 
		"Name=order[0][column]", "Value=3", ENDITEM, 
		"Name=order[0][dir]", "Value=desc", ENDITEM, 
		"Name=start", "Value=0", ENDITEM, 
		"Name=length", "Value=5", ENDITEM, 
		"Name=search[value]", "Value=", ENDITEM, 
		"Name=search[regex]", "Value=false", ENDITEM, 
		"Name=loadData", "Value=true", ENDITEM, 
		LAST);

	web_revert_auto_header("Origin");

	web_revert_auto_header("X-CSRF-TOKEN");

	web_url("casePrioritySelect.hbs", 
		"URL={PVI_URL}/assets/common/hbs-templates/casePrioritySelect.hbs", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/", 
		"Snapshot=t67.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("Origin", 
		"{PVI_URL}");

	web_add_header("X-CSRF-TOKEN",
		"{TokenId2}");

	web_submit_data("2_2", 
		"Action={PVI_URL}/case/rest/list/2", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/", 
		"Snapshot=t68.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=draw", "Value=2", ENDITEM, 
		"Name=columns[0][data]", "Value=selected", ENDITEM, 
		"Name=columns[0][name]", "Value=selected", ENDITEM, 
		"Name=columns[0][searchable]", "Value=true", ENDITEM, 
		"Name=columns[0][orderable]", "Value=false", ENDITEM, 
		"Name=columns[0][search][value]", "Value=", ENDITEM, 
		"Name=columns[0][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[1][data]", "Value=intakeCaseNumber", ENDITEM, 
		"Name=columns[1][name]", "Value=intakeCaseNumber", ENDITEM, 
		"Name=columns[1][searchable]", "Value=true", ENDITEM, 
		"Name=columns[1][orderable]", "Value=true", ENDITEM, 
		"Name=columns[1][search][value]", "Value=", ENDITEM, 
		"Name=columns[1][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[2][data]", "Value=firstReceiptDateString", ENDITEM, 
		"Name=columns[2][name]", "Value=firstReceiptDate", ENDITEM, 
		"Name=columns[2][searchable]", "Value=true", ENDITEM, 
		"Name=columns[2][orderable]", "Value=true", ENDITEM, 
		"Name=columns[2][search][value]", "Value=", ENDITEM, 
		"Name=columns[2][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[3][data]", "Value=products", ENDITEM, 
		"Name=columns[3][name]", "Value=products.name", ENDITEM, 
		"Name=columns[3][searchable]", "Value=true", ENDITEM, 
		"Name=columns[3][orderable]", "Value=false", ENDITEM, 
		"Name=columns[3][search][value]", "Value=", ENDITEM, 
		"Name=columns[3][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[4][data]", "Value=attachments", ENDITEM, 
		"Name=columns[4][name]", "Value=attachments.name", ENDITEM, 
		"Name=columns[4][searchable]", "Value=true", ENDITEM, 
		"Name=columns[4][orderable]", "Value=false", ENDITEM, 
		"Name=columns[4][search][value]", "Value=", ENDITEM, 
		"Name=columns[4][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[5][data]", "Value=senderType", ENDITEM, 
		"Name=columns[5][name]", "Value=senderType.value", ENDITEM, 
		"Name=columns[5][searchable]", "Value=true", ENDITEM, 
		"Name=columns[5][orderable]", "Value=true", ENDITEM, 
		"Name=columns[5][search][value]", "Value=", ENDITEM, 
		"Name=columns[5][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[6][data]", "Value=senderName", ENDITEM, 
		"Name=columns[6][name]", "Value=senderName", ENDITEM, 
		"Name=columns[6][searchable]", "Value=true", ENDITEM, 
		"Name=columns[6][orderable]", "Value=true", ENDITEM, 
		"Name=columns[6][search][value]", "Value=", ENDITEM, 
		"Name=columns[6][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[7][data]", "Value=assignedToUsername", ENDITEM, 
		"Name=columns[7][name]", "Value=assignedToUsername", ENDITEM, 
		"Name=columns[7][searchable]", "Value=true", ENDITEM, 
		"Name=columns[7][orderable]", "Value=true", ENDITEM, 
		"Name=columns[7][search][value]", "Value=", ENDITEM, 
		"Name=columns[7][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[8][data]", "Value=caseVersion", ENDITEM, 
		"Name=columns[8][name]", "Value=caseVersion", ENDITEM, 
		"Name=columns[8][searchable]", "Value=true", ENDITEM, 
		"Name=columns[8][orderable]", "Value=true", ENDITEM, 
		"Name=columns[8][search][value]", "Value=", ENDITEM, 
		"Name=columns[8][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[9][data]", "Value=reporterQualification", ENDITEM, 
		"Name=columns[9][name]", "Value=reporters.qualificationValue", ENDITEM, 
		"Name=columns[9][searchable]", "Value=true", ENDITEM, 
		"Name=columns[9][orderable]", "Value=true", ENDITEM, 
		"Name=columns[9][search][value]", "Value=", ENDITEM, 
		"Name=columns[9][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[10][data]", "Value=events", ENDITEM, 
		"Name=columns[10][name]", "Value=events.eventName", ENDITEM, 
		"Name=columns[10][searchable]", "Value=true", ENDITEM, 
		"Name=columns[10][orderable]", "Value=false", ENDITEM, 
		"Name=columns[10][search][value]", "Value=", ENDITEM, 
		"Name=columns[10][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[11][data]", "Value=caseSeriousness", ENDITEM, 
		"Name=columns[11][name]", "Value=caseSeriousness.category", ENDITEM, 
		"Name=columns[11][searchable]", "Value=true", ENDITEM, 
		"Name=columns[11][orderable]", "Value=true", ENDITEM, 
		"Name=columns[11][search][value]", "Value=", ENDITEM, 
		"Name=columns[11][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[12][data]", "Value=priority", ENDITEM, 
		"Name=columns[12][name]", "Value=priority.value", ENDITEM, 
		"Name=columns[12][searchable]", "Value=true", ENDITEM, 
		"Name=columns[12][orderable]", "Value=true", ENDITEM, 
		"Name=columns[12][search][value]", "Value=", ENDITEM, 
		"Name=columns[12][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[13][data]", "Value=dueDateString", ENDITEM, 
		"Name=columns[13][name]", "Value=dueDate", ENDITEM, 
		"Name=columns[13][searchable]", "Value=true", ENDITEM, 
		"Name=columns[13][orderable]", "Value=true", ENDITEM, 
		"Name=columns[13][search][value]", "Value=", ENDITEM, 
		"Name=columns[13][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[14][data]", "Value=isRelated", ENDITEM, 
		"Name=columns[14][name]", "Value=isRelated", ENDITEM, 
		"Name=columns[14][searchable]", "Value=true", ENDITEM, 
		"Name=columns[14][orderable]", "Value=true", ENDITEM, 
		"Name=columns[14][search][value]", "Value=", ENDITEM, 
		"Name=columns[14][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[15][data]", "Value=safetyCaseNumber", ENDITEM, 
		"Name=columns[15][name]", "Value=safetyCaseNumber", ENDITEM, 
		"Name=columns[15][searchable]", "Value=true", ENDITEM, 
		"Name=columns[15][orderable]", "Value=true", ENDITEM, 
		"Name=columns[15][search][value]", "Value=", ENDITEM, 
		"Name=columns[15][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[16][data]", "Value=reportType", ENDITEM, 
		"Name=columns[16][name]", "Value=reportType", ENDITEM, 
		"Name=columns[16][searchable]", "Value=true", ENDITEM, 
		"Name=columns[16][orderable]", "Value=true", ENDITEM, 
		"Name=columns[16][search][value]", "Value=", ENDITEM, 
		"Name=columns[16][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[17][data]", "Value=patientAge", ENDITEM, 
		"Name=columns[17][name]", "Value=patientAge", ENDITEM, 
		"Name=columns[17][searchable]", "Value=true", ENDITEM, 
		"Name=columns[17][orderable]", "Value=false", ENDITEM, 
		"Name=columns[17][search][value]", "Value=", ENDITEM, 
		"Name=columns[17][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[18][data]", "Value=gender", ENDITEM, 
		"Name=columns[18][name]", "Value=gender.value", ENDITEM, 
		"Name=columns[18][searchable]", "Value=true", ENDITEM, 
		"Name=columns[18][orderable]", "Value=true", ENDITEM, 
		"Name=columns[18][search][value]", "Value=", ENDITEM, 
		"Name=columns[18][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[19][data]", "Value=destination", ENDITEM, 
		"Name=columns[19][name]", "Value=icsr.destination", ENDITEM, 
		"Name=columns[19][searchable]", "Value=true", ENDITEM, 
		"Name=columns[19][orderable]", "Value=true", ENDITEM, 
		"Name=columns[19][search][value]", "Value=", ENDITEM, 
		"Name=columns[19][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[20][data]", "Value=reportDueDateString", ENDITEM, 
		"Name=columns[20][name]", "Value=icsr.dueDate", ENDITEM, 
		"Name=columns[20][searchable]", "Value=true", ENDITEM, 
		"Name=columns[20][orderable]", "Value=true", ENDITEM, 
		"Name=columns[20][search][value]", "Value=", ENDITEM, 
		"Name=columns[20][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[21][data]", "Value=reporterComments", ENDITEM, 
		"Name=columns[21][name]", "Value=reporterComments", ENDITEM, 
		"Name=columns[21][searchable]", "Value=true", ENDITEM, 
		"Name=columns[21][orderable]", "Value=false", ENDITEM, 
		"Name=columns[21][search][value]", "Value=", ENDITEM, 
		"Name=columns[21][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[22][data]", "Value=reporters", ENDITEM, 
		"Name=columns[22][name]", "Value=reporters.name", ENDITEM, 
		"Name=columns[22][searchable]", "Value=true", ENDITEM, 
		"Name=columns[22][orderable]", "Value=true", ENDITEM, 
		"Name=columns[22][search][value]", "Value=", ENDITEM, 
		"Name=columns[22][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[23][data]", "Value=eventCountry", ENDITEM, 
		"Name=columns[23][name]", "Value=eventCountry.name", ENDITEM, 
		"Name=columns[23][searchable]", "Value=true", ENDITEM, 
		"Name=columns[23][orderable]", "Value=true", ENDITEM, 
		"Name=columns[23][search][value]", "Value=", ENDITEM, 
		"Name=columns[23][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[24][data]", "Value=reportVersion", ENDITEM, 
		"Name=columns[24][name]", "Value=icsr.reportVersion", ENDITEM, 
		"Name=columns[24][searchable]", "Value=true", ENDITEM, 
		"Name=columns[24][orderable]", "Value=true", ENDITEM, 
		"Name=columns[24][search][value]", "Value=", ENDITEM, 
		"Name=columns[24][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[25][data]", "Value=icsr", ENDITEM, 
		"Name=columns[25][name]", "Value=icsr.transmissionStatus", ENDITEM, 
		"Name=columns[25][searchable]", "Value=true", ENDITEM, 
		"Name=columns[25][orderable]", "Value=true", ENDITEM, 
		"Name=columns[25][search][value]", "Value=", ENDITEM, 
		"Name=columns[25][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[26][data]", "Value=stateTimestampString", ENDITEM, 
		"Name=columns[26][name]", "Value=icsr.stateTimestamp", ENDITEM, 
		"Name=columns[26][searchable]", "Value=true", ENDITEM, 
		"Name=columns[26][orderable]", "Value=true", ENDITEM, 
		"Name=columns[26][search][value]", "Value=", ENDITEM, 
		"Name=columns[26][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[27][data]", "Value=reportMessage", ENDITEM, 
		"Name=columns[27][name]", "Value=icsr.reportMessage", ENDITEM, 
		"Name=columns[27][searchable]", "Value=true", ENDITEM, 
		"Name=columns[27][orderable]", "Value=false", ENDITEM, 
		"Name=columns[27][search][value]", "Value=", ENDITEM, 
		"Name=columns[27][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[28][data]", "Value=eventName", ENDITEM, 
		"Name=columns[28][name]", "Value=eventName", ENDITEM, 
		"Name=columns[28][searchable]", "Value=true", ENDITEM, 
		"Name=columns[28][orderable]", "Value=true", ENDITEM, 
		"Name=columns[28][search][value]", "Value=", ENDITEM, 
		"Name=columns[28][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[29][data]", "Value=eventStartDate", ENDITEM, 
		"Name=columns[29][name]", "Value=eventStartDate", ENDITEM, 
		"Name=columns[29][searchable]", "Value=true", ENDITEM, 
		"Name=columns[29][orderable]", "Value=true", ENDITEM, 
		"Name=columns[29][search][value]", "Value=", ENDITEM, 
		"Name=columns[29][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[30][data]", "Value=outcome", ENDITEM, 
		"Name=columns[30][name]", "Value=outcome.value", ENDITEM, 
		"Name=columns[30][searchable]", "Value=true", ENDITEM, 
		"Name=columns[30][orderable]", "Value=true", ENDITEM, 
		"Name=columns[30][search][value]", "Value=", ENDITEM, 
		"Name=columns[30][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[31][data]", "Value=reporterCountry", ENDITEM, 
		"Name=columns[31][name]", "Value=reporters.countryName", ENDITEM, 
		"Name=columns[31][searchable]", "Value=true", ENDITEM, 
		"Name=columns[31][orderable]", "Value=true", ENDITEM, 
		"Name=columns[31][search][value]", "Value=", ENDITEM, 
		"Name=columns[31][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[32][data]", "Value=relatednessString", ENDITEM, 
		"Name=columns[32][name]", "Value=relatednessString", ENDITEM, 
		"Name=columns[32][searchable]", "Value=true", ENDITEM, 
		"Name=columns[32][orderable]", "Value=true", ENDITEM, 
		"Name=columns[32][search][value]", "Value=", ENDITEM, 
		"Name=columns[32][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[33][data]", "Value=sourceType", ENDITEM, 
		"Name=columns[33][name]", "Value=sourceType.type", ENDITEM, 
		"Name=columns[33][searchable]", "Value=true", ENDITEM, 
		"Name=columns[33][orderable]", "Value=true", ENDITEM, 
		"Name=columns[33][search][value]", "Value=", ENDITEM, 
		"Name=columns[33][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[34][data]", "Value=categories", ENDITEM, 
		"Name=columns[34][name]", "Value=categories.value", ENDITEM, 
		"Name=columns[34][searchable]", "Value=true", ENDITEM, 
		"Name=columns[34][orderable]", "Value=false", ENDITEM, 
		"Name=columns[34][search][value]", "Value=", ENDITEM, 
		"Name=columns[34][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[35][data]", "Value=mostRecentReceiptDateString", ENDITEM, 
		"Name=columns[35][name]", "Value=mostRecentReceiptDate", ENDITEM, 
		"Name=columns[35][searchable]", "Value=true", ENDITEM, 
		"Name=columns[35][orderable]", "Value=true", ENDITEM, 
		"Name=columns[35][search][value]", "Value=", ENDITEM, 
		"Name=columns[35][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[36][data]", "Value=productName", ENDITEM, 
		"Name=columns[36][name]", "Value=productName", ENDITEM, 
		"Name=columns[36][searchable]", "Value=true", ENDITEM, 
		"Name=columns[36][orderable]", "Value=true", ENDITEM, 
		"Name=columns[36][search][value]", "Value=", ENDITEM, 
		"Name=columns[36][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[37][data]", "Value=substances", ENDITEM, 
		"Name=columns[37][name]", "Value=substances.nameValue", ENDITEM, 
		"Name=columns[37][searchable]", "Value=true", ENDITEM, 
		"Name=columns[37][orderable]", "Value=false", ENDITEM, 
		"Name=columns[37][search][value]", "Value=", ENDITEM, 
		"Name=columns[37][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[38][data]", "Value=studyNumber", ENDITEM, 
		"Name=columns[38][name]", "Value=studyNumber", ENDITEM, 
		"Name=columns[38][searchable]", "Value=true", ENDITEM, 
		"Name=columns[38][orderable]", "Value=true", ENDITEM, 
		"Name=columns[38][search][value]", "Value=", ENDITEM, 
		"Name=columns[38][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[39][data]", "Value=caseState", ENDITEM, 
		"Name=columns[39][name]", "Value=caseState", ENDITEM, 
		"Name=columns[39][searchable]", "Value=true", ENDITEM, 
		"Name=columns[39][orderable]", "Value=true", ENDITEM, 
		"Name=columns[39][search][value]", "Value=", ENDITEM, 
		"Name=columns[39][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[40][data]", "Value=versionType", ENDITEM, 
		"Name=columns[40][name]", "Value=versionType.value", ENDITEM, 
		"Name=columns[40][searchable]", "Value=true", ENDITEM, 
		"Name=columns[40][orderable]", "Value=true", ENDITEM, 
		"Name=columns[40][search][value]", "Value=", ENDITEM, 
		"Name=columns[40][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[41][data]", "Value=receiptDateString", ENDITEM, 
		"Name=columns[41][name]", "Value=receiptDate", ENDITEM, 
		"Name=columns[41][searchable]", "Value=true", ENDITEM, 
		"Name=columns[41][orderable]", "Value=false", ENDITEM, 
		"Name=columns[41][search][value]", "Value=", ENDITEM, 
		"Name=columns[41][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[42][data]", "Value=onsetDate", ENDITEM, 
		"Name=columns[42][name]", "Value=onsetDate", ENDITEM, 
		"Name=columns[42][searchable]", "Value=true", ENDITEM, 
		"Name=columns[42][orderable]", "Value=true", ENDITEM, 
		"Name=columns[42][search][value]", "Value=", ENDITEM, 
		"Name=columns[42][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[43][data]", "Value=submissionDate", ENDITEM, 
		"Name=columns[43][name]", "Value=submissionDate", ENDITEM, 
		"Name=columns[43][searchable]", "Value=true", ENDITEM, 
		"Name=columns[43][orderable]", "Value=true", ENDITEM, 
		"Name=columns[43][search][value]", "Value=", ENDITEM, 
		"Name=columns[43][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[44][data]", "Value=dosageForm", ENDITEM, 
		"Name=columns[44][name]", "Value=dosageForm.value", ENDITEM, 
		"Name=columns[44][searchable]", "Value=true", ENDITEM, 
		"Name=columns[44][orderable]", "Value=true", ENDITEM, 
		"Name=columns[44][search][value]", "Value=", ENDITEM, 
		"Name=columns[44][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[45][data]", "Value=caseVersionType", ENDITEM, 
		"Name=columns[45][name]", "Value=caseVersionType", ENDITEM, 
		"Name=columns[45][searchable]", "Value=true", ENDITEM, 
		"Name=columns[45][orderable]", "Value=true", ENDITEM, 
		"Name=columns[45][search][value]", "Value=", ENDITEM, 
		"Name=columns[45][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[46][data]", "Value=icsrType", ENDITEM, 
		"Name=columns[46][name]", "Value=icsr.type", ENDITEM, 
		"Name=columns[46][searchable]", "Value=true", ENDITEM, 
		"Name=columns[46][orderable]", "Value=true", ENDITEM, 
		"Name=columns[46][search][value]", "Value=", ENDITEM, 
		"Name=columns[46][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[47][data]", "Value=studyType", ENDITEM, 
		"Name=columns[47][name]", "Value=studyType.value", ENDITEM, 
		"Name=columns[47][searchable]", "Value=true", ENDITEM, 
		"Name=columns[47][orderable]", "Value=true", ENDITEM, 
		"Name=columns[47][search][value]", "Value=", ENDITEM, 
		"Name=columns[47][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[48][data]", "Value=patientName", ENDITEM, 
		"Name=columns[48][name]", "Value=patientName", ENDITEM, 
		"Name=columns[48][searchable]", "Value=true", ENDITEM, 
		"Name=columns[48][orderable]", "Value=true", ENDITEM, 
		"Name=columns[48][search][value]", "Value=", ENDITEM, 
		"Name=columns[48][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[49][data]", "Value=seriousness", ENDITEM, 
		"Name=columns[49][name]", "Value=seriousnessString", ENDITEM, 
		"Name=columns[49][searchable]", "Value=true", ENDITEM, 
		"Name=columns[49][orderable]", "Value=false", ENDITEM, 
		"Name=columns[49][search][value]", "Value=", ENDITEM, 
		"Name=columns[49][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[50][data]", "Value=caseCountry", ENDITEM, 
		"Name=columns[50][name]", "Value=caseCountry.name", ENDITEM, 
		"Name=columns[50][searchable]", "Value=true", ENDITEM, 
		"Name=columns[50][orderable]", "Value=true", ENDITEM, 
		"Name=columns[50][search][value]", "Value=", ENDITEM, 
		"Name=columns[50][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[51][data]", "Value=allReferences", ENDITEM, 
		"Name=columns[51][name]", "Value=allReferences", ENDITEM, 
		"Name=columns[51][searchable]", "Value=true", ENDITEM, 
		"Name=columns[51][orderable]", "Value=false", ENDITEM, 
		"Name=columns[51][search][value]", "Value=", ENDITEM, 
		"Name=columns[51][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[52][data]", "Value=patientId", ENDITEM, 
		"Name=columns[52][name]", "Value=patientId", ENDITEM, 
		"Name=columns[52][searchable]", "Value=true", ENDITEM, 
		"Name=columns[52][orderable]", "Value=true", ENDITEM, 
		"Name=columns[52][search][value]", "Value=", ENDITEM, 
		"Name=columns[52][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[53][data]", "Value=dobString", ENDITEM, 
		"Name=columns[53][name]", "Value=dob", ENDITEM, 
		"Name=columns[53][searchable]", "Value=true", ENDITEM, 
		"Name=columns[53][orderable]", "Value=true", ENDITEM, 
		"Name=columns[53][search][value]", "Value=", ENDITEM, 
		"Name=columns[53][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[54][data]", "Value=matchScore", ENDITEM, 
		"Name=columns[54][name]", "Value=matchScore", ENDITEM, 
		"Name=columns[54][searchable]", "Value=true", ENDITEM, 
		"Name=columns[54][orderable]", "Value=true", ENDITEM, 
		"Name=columns[54][search][value]", "Value=", ENDITEM, 
		"Name=columns[54][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[55][data]", "Value=simpleSearch", ENDITEM, 
		"Name=columns[55][name]", "Value=simpleSearch", ENDITEM, 
		"Name=columns[55][searchable]", "Value=true", ENDITEM, 
		"Name=columns[55][orderable]", "Value=true", ENDITEM, 
		"Name=columns[55][search][value]", "Value={\"simpleSearch\":\"\",\"caseStateId\":\"1,2\",\"config\":\"{\\\"isOrOperation\\\": \\\"false\\\", \\\"sortWhileSearch\\\": \\\"false\\\", \\\"countSearchCriteria\\\": \\\"false\\\"}\",\"sourceDbId\":\"1\",\"firstReceiptDate\":\"{\\\"gte\\\":\\\"2019-08-29T00:00:00Z\\\",\\\"lte\\\":\\\"2020-08-27T23:59:59Z\\\"}\"}", ENDITEM, 
		"Name=columns[55][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[56][data]", "Value=dateRangeSearch", ENDITEM, 
		"Name=columns[56][name]", "Value=dateRangeSearch", ENDITEM, 
		"Name=columns[56][searchable]", "Value=true", ENDITEM, 
		"Name=columns[56][orderable]", "Value=true", ENDITEM, 
		"Name=columns[56][search][value]", "Value=", ENDITEM, 
		"Name=columns[56][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[57][data]", "Value=sourceDb", ENDITEM, 
		"Name=columns[57][name]", "Value=sourceDb", ENDITEM, 
		"Name=columns[57][searchable]", "Value=true", ENDITEM, 
		"Name=columns[57][orderable]", "Value=true", ENDITEM, 
		"Name=columns[57][search][value]", "Value=", ENDITEM, 
		"Name=columns[57][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[58][data]", "Value=safetyWFState", ENDITEM, 
		"Name=columns[58][name]", "Value=safetyWFState", ENDITEM, 
		"Name=columns[58][searchable]", "Value=true", ENDITEM, 
		"Name=columns[58][orderable]", "Value=true", ENDITEM, 
		"Name=columns[58][search][value]", "Value=", ENDITEM, 
		"Name=columns[58][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[59][data]", "Value=centralReceiptDateString", ENDITEM, 
		"Name=columns[59][name]", "Value=centralReceiptDate", ENDITEM, 
		"Name=columns[59][searchable]", "Value=true", ENDITEM, 
		"Name=columns[59][orderable]", "Value=true", ENDITEM, 
		"Name=columns[59][search][value]", "Value=", ENDITEM, 
		"Name=columns[59][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[60][data]", "Value=localSubmissionDateString", ENDITEM, 
		"Name=columns[60][name]", "Value=localSubmissionDate", ENDITEM, 
		"Name=columns[60][searchable]", "Value=true", ENDITEM, 
		"Name=columns[60][orderable]", "Value=true", ENDITEM, 
		"Name=columns[60][search][value]", "Value=", ENDITEM, 
		"Name=columns[60][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[61][data]", "Value=localSubmissionDueDateString", ENDITEM, 
		"Name=columns[61][name]", "Value=localSubmissionDueDate", ENDITEM, 
		"Name=columns[61][searchable]", "Value=true", ENDITEM, 
		"Name=columns[61][orderable]", "Value=true", ENDITEM, 
		"Name=columns[61][search][value]", "Value=", ENDITEM, 
		"Name=columns[61][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[62][data]", "Value=latestAssignmentComment", ENDITEM, 
		"Name=columns[62][name]", "Value=latestAssignmentComment", ENDITEM, 
		"Name=columns[62][searchable]", "Value=true", ENDITEM, 
		"Name=columns[62][orderable]", "Value=false", ENDITEM, 
		"Name=columns[62][search][value]", "Value=", ENDITEM, 
		"Name=columns[62][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[63][data]", "Value=vendor", ENDITEM, 
		"Name=columns[63][name]", "Value=vendor", ENDITEM, 
		"Name=columns[63][searchable]", "Value=true", ENDITEM, 
		"Name=columns[63][orderable]", "Value=true", ENDITEM, 
		"Name=columns[63][search][value]", "Value=", ENDITEM, 
		"Name=columns[63][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[64][data]", "Value=replacementRequired", ENDITEM, 
		"Name=columns[64][name]", "Value=replacementRequired", ENDITEM, 
		"Name=columns[64][searchable]", "Value=true", ENDITEM, 
		"Name=columns[64][orderable]", "Value=true", ENDITEM, 
		"Name=columns[64][search][value]", "Value=", ENDITEM, 
		"Name=columns[64][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[65][data]", "Value=caseCreatedDate", ENDITEM, 
		"Name=columns[65][name]", "Value=caseCreatedDate", ENDITEM, 
		"Name=columns[65][searchable]", "Value=true", ENDITEM, 
		"Name=columns[65][orderable]", "Value=true", ENDITEM, 
		"Name=columns[65][search][value]", "Value=", ENDITEM, 
		"Name=columns[65][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[66][data]", "Value=reporters", ENDITEM, 
		"Name=columns[66][name]", "Value=reporters.organization", ENDITEM, 
		"Name=columns[66][searchable]", "Value=true", ENDITEM, 
		"Name=columns[66][orderable]", "Value=true", ENDITEM, 
		"Name=columns[66][search][value]", "Value=", ENDITEM, 
		"Name=columns[66][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[67][data]", "Value=reporters", ENDITEM, 
		"Name=columns[67][name]", "Value=reporters.department", ENDITEM, 
		"Name=columns[67][searchable]", "Value=true", ENDITEM, 
		"Name=columns[67][orderable]", "Value=true", ENDITEM, 
		"Name=columns[67][search][value]", "Value=", ENDITEM, 
		"Name=columns[67][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[68][data]", "Value=reporters", ENDITEM, 
		"Name=columns[68][name]", "Value=reporters.address", ENDITEM, 
		"Name=columns[68][searchable]", "Value=true", ENDITEM, 
		"Name=columns[68][orderable]", "Value=true", ENDITEM, 
		"Name=columns[68][search][value]", "Value=", ENDITEM, 
		"Name=columns[68][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[69][data]", "Value=reporters", ENDITEM, 
		"Name=columns[69][name]", "Value=reporters.telephone", ENDITEM, 
		"Name=columns[69][searchable]", "Value=true", ENDITEM, 
		"Name=columns[69][orderable]", "Value=true", ENDITEM, 
		"Name=columns[69][search][value]", "Value=", ENDITEM, 
		"Name=columns[69][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[70][data]", "Value=reporters", ENDITEM, 
		"Name=columns[70][name]", "Value=reporters.faxNumber", ENDITEM, 
		"Name=columns[70][searchable]", "Value=true", ENDITEM, 
		"Name=columns[70][orderable]", "Value=true", ENDITEM, 
		"Name=columns[70][search][value]", "Value=", ENDITEM, 
		"Name=columns[70][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[71][data]", "Value=reporters", ENDITEM, 
		"Name=columns[71][name]", "Value=reporters.email", ENDITEM, 
		"Name=columns[71][searchable]", "Value=true", ENDITEM, 
		"Name=columns[71][orderable]", "Value=true", ENDITEM, 
		"Name=columns[71][search][value]", "Value=", ENDITEM, 
		"Name=columns[71][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[72][data]", "Value=pqcCaseNumber", ENDITEM, 
		"Name=columns[72][name]", "Value=pqcCaseNumber", ENDITEM, 
		"Name=columns[72][searchable]", "Value=true", ENDITEM, 
		"Name=columns[72][orderable]", "Value=true", ENDITEM, 
		"Name=columns[72][search][value]", "Value=", ENDITEM, 
		"Name=columns[72][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[73][data]", "Value=returnRequired", ENDITEM, 
		"Name=columns[73][name]", "Value=returnRequired", ENDITEM, 
		"Name=columns[73][searchable]", "Value=true", ENDITEM, 
		"Name=columns[73][orderable]", "Value=true", ENDITEM, 
		"Name=columns[73][search][value]", "Value=", ENDITEM, 
		"Name=columns[73][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[74][data]", "Value=refundRequested", ENDITEM, 
		"Name=columns[74][name]", "Value=refundRequested", ENDITEM, 
		"Name=columns[74][searchable]", "Value=true", ENDITEM, 
		"Name=columns[74][orderable]", "Value=true", ENDITEM, 
		"Name=columns[74][search][value]", "Value=", ENDITEM, 
		"Name=columns[74][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[75][data]", "Value=reporters", ENDITEM, 
		"Name=columns[75][name]", "Value=reporters.contactTypes.value", ENDITEM, 
		"Name=columns[75][searchable]", "Value=true", ENDITEM, 
		"Name=columns[75][orderable]", "Value=false", ENDITEM, 
		"Name=columns[75][search][value]", "Value=", ENDITEM, 
		"Name=columns[75][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[76][data]", "Value=action", ENDITEM, 
		"Name=columns[76][name]", "Value=", ENDITEM, 
		"Name=columns[76][searchable]", "Value=true", ENDITEM, 
		"Name=columns[76][orderable]", "Value=false", ENDITEM, 
		"Name=columns[76][search][value]", "Value=", ENDITEM, 
		"Name=columns[76][search][regex]", "Value=false", ENDITEM, 
		"Name=order[0][column]", "Value=2", ENDITEM, 
		"Name=order[0][dir]", "Value=desc", ENDITEM, 
		"Name=start", "Value=0", ENDITEM, 
		"Name=length", "Value=5", ENDITEM, 
		"Name=search[value]", "Value=", ENDITEM, 
		"Name=search[regex]", "Value=false", ENDITEM, 
		"Name=loadData", "Value=true", ENDITEM, 
		LAST);

	web_url("viewAction.hbs", 
		"URL={PVI_URL}/assets/common/hbs-templates/viewAction.hbs", 
		"Resource=1", 
		"Referer={PVI_URL}/", 
		"Snapshot=t69.inf", 
		LAST);

	web_url("getActionViewList", 
		"URL={PVI_URL}/case/getActionViewList?pageId=1&sourceDbId=1&_=1598531772280", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/", 
		"Snapshot=t70.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("FollowUp_03_NavigateToPVIntake",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("FollowUp_04_NavigateDuplicateSearchScreen");

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("Accept", 
		"text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_reg_find("Search=Body",
		"Text=Duplicate Search",
		LAST);

	web_url("search", 
		"URL={PVI_URL}/duplicate/search", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/", 
		"Snapshot=t71.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_start(NULL);

	web_url("list-24eb5f840484c7ed5a76f95c9fe17ba2.css", 
		"URL={PVI_URL}/assets/list/list-24eb5f840484c7ed5a76f95c9fe17ba2.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t72.inf", 
		LAST);

	web_url("attachmentViewer-manifest-d21cd5ef9afc9d23b8e3146c7832bb09.css", 
		"URL={PVI_URL}/assets/vendor/documentViewer/attachmentViewer-manifest-d21cd5ef9afc9d23b8e3146c7832bb09.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t73.inf", 
		LAST);

	web_url("duplicate-search-manifest-0b2a8a36660d47799410a8152206eef0.js", 
		"URL={PVI_URL}/assets/app/duplicate-search/duplicate-search-manifest-0b2a8a36660d47799410a8152206eef0.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t74.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_add_auto_header("Accept", 
		"*/*");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("en-US.json_2", 
		"URL={PVI_URL}/assets/vendor/documentViewerJson/en-US.json?_=1598531812901", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t75.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("redactionReason.json_2", 
		"URL={PVI_URL}/assets/vendor/documentViewerJson/redactionReason.json?_=1598531812903", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t76.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("predefinedSearch.json_2", 
		"URL={PVI_URL}/assets/vendor/documentViewerJson/predefinedSearch.json?_=1598531812902", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t77.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("downloadOverlayTemplate.html_2", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/downloadOverlayTemplate.html?_=1598531812907", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t78.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("esignOverlayTemplate.html_2", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/esignOverlayTemplate.html?_=1598531812908", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t79.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("commentTemplate.html_2", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/commentTemplate.html?_=1598531812904", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t80.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("copyOverlayTemplate.html_2", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/copyOverlayTemplate.html?_=1598531812906", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t81.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("hyperlinkMenuTemplate.html_2", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/hyperlinkMenuTemplate.html?_=1598531812909", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t82.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("printTemplate.html_2", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/printTemplate.html?_=1598531812914", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t83.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("overwriteOverlayTemplate.html_2", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/overwriteOverlayTemplate.html?_=1598531812911", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t84.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("pageRedactionOverlayTemplate.html_2", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/pageRedactionOverlayTemplate.html?_=1598531812912", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t85.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("imageStampOverlayTemplate.html_2", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/imageStampOverlayTemplate.html?_=1598531812910", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t86.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("printOverlayTemplate.html_2", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/printOverlayTemplate.html?_=1598531812913", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t87.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("unsavedChangesOverlayTemplate.html_2", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/unsavedChangesOverlayTemplate.html?_=1598531812916", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t88.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("redactionReasonTemplate.html_2", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/redactionReasonTemplate.html?_=1598531812915", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t89.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("viewerTemplate.html_2", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/viewerTemplate.html?_=1598531812917", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t90.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("4", 
		"URL={PVI_URL}/case/rest/list_columns/4?_=1598531812918", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t91.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("fetchReferenceData", 
		"URL={PVI_URL}/caseEntry/fetchReferenceData?_=1598531812919", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t92.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_auto_header("Accept", 
		"application/json, text/javascript, */*; q=0.01");

	web_url("loadServerTime_2", 
		"URL={PVI_URL}/config/loadServerTime?_=1598531812920", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t93.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_auto_header("Accept", 
		"*/*");

	web_add_auto_header("Origin", 
		"{PVI_URL}");

	web_add_auto_header("X-CSRF-TOKEN",
		"{TokenId2}");

	web_submit_data("loadState_3", 
		"Action={PVI_URL}/user/loadState", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t94.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=pageType", "Value=duplicateSearchForm", ENDITEM, 
		"Name=section", "Value=DataTable", ENDITEM, 
		LAST);

	web_url("product_template.hbs", 
		"URL={PVI_URL}/assets/pv/comp/templates/product_template.hbs", 
		"Resource=1", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t95.inf", 
		LAST);

	web_submit_data("saveState", 
		"Action={PVI_URL}/user/saveState", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t96.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=data", "Value={\"time\":1598531818872,\"start\":0,\"length\":10,\"order\":[],\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true},\"columns\":[{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\""
		"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\""
		"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\""
		"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\""
		"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\""
		"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\""
		"search\":\"{\\\"caseStateId\\\":\\\"2,3,4,5,6,11\\\",\\\"config\\\":\\\"{\\\\\\\"isOrOperation\\\\\\\": \\\\\\\"true\\\\\\\", \\\\\\\"sortWhileSearch\\\\\\\": \\\\\\\"true\\\\\\\", \\\\\\\"countSearchCriteria\\\\\\\": \\\\\\\"true\\\\\\\"}\\\",\\\"isLatestValidVersion\\\":true,\\\"sourceDbId\\\":\\\"1\\\",\\\"firstReceiptDate\\\":\\\"{\\\\\\\"gte\\\\\\\":\\\\\\\"2019-08-29T00:00:00Z\\\\\\\",\\\\\\\"lte\\\\\\\":\\\\\\\"2020-08-27T23:59:59Z\\\\\\\"}\\\"}\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\""
		"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\""
		"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}}],\"ColReorder\":[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76]}", ENDITEM, 
		"Name=pageType", "Value=duplicateSearchForm", ENDITEM, 
		"Name=section", "Value=DataTable", ENDITEM, 
		LAST);

	web_submit_data("saveState_2", 
		"Action={PVI_URL}/user/saveState", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t97.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=data", "Value={\"time\":1598531818963,\"start\":0,\"length\":10,\"order\":[],\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true},\"columns\":[{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\""
		"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\""
		"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\""
		"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\""
		"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\""
		"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\""
		"search\":\"{\\\"caseStateId\\\":\\\"2,3,4,5,6,11\\\",\\\"config\\\":\\\"{\\\\\\\"isOrOperation\\\\\\\": \\\\\\\"true\\\\\\\", \\\\\\\"sortWhileSearch\\\\\\\": \\\\\\\"true\\\\\\\", \\\\\\\"countSearchCriteria\\\\\\\": \\\\\\\"true\\\\\\\"}\\\",\\\"isLatestValidVersion\\\":true,\\\"sourceDbId\\\":\\\"1\\\",\\\"firstReceiptDate\\\":\\\"{\\\\\\\"gte\\\\\\\":\\\\\\\"2019-08-29T00:00:00Z\\\\\\\",\\\\\\\"lte\\\\\\\":\\\\\\\"2020-08-27T23:59:59Z\\\\\\\"}\\\"}\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\""
		"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\""
		"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}}],\"ColReorder\":[0,1,35,33,15,16,6,48,5,49,50,51,52,53,54,2,3,4,7,8,9,10,11,12,13,14,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,34,36,37,38,39,40,41,42,43,44,45,46,47,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76]}", ENDITEM, 
		"Name=pageType", "Value=duplicateSearchForm", ENDITEM, 
		"Name=section", "Value=DataTable", ENDITEM, 
		LAST);

	web_url("product_browser.hbs", 
		"URL={PVI_URL}/assets/pv/comp/templates/product_browser.hbs", 
		"Resource=1", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t98.inf", 
		LAST);

	web_revert_auto_header("Origin");

	web_revert_auto_header("X-CSRF-TOKEN");

	web_url("contextMenuTemplate.html_2", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/contextMenuTemplate.html?_=1598531812905", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t99.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_start(NULL);

	web_url("meddra_template.hbs", 
		"URL={PVI_URL}/assets/pv/comp/templates/meddra_template.hbs", 
		"Resource=1", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t100.inf", 
		LAST);

	web_url("meddra_browser.hbs", 
		"URL={PVI_URL}/assets/pv/comp/templates/meddra_browser.hbs", 
		"Resource=1", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t101.inf", 
		LAST);

	web_url("study_template.hbs", 
		"URL={PVI_URL}/assets/pv/comp/templates/study_template.hbs", 
		"Resource=1", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t102.inf", 
		LAST);

	web_url("study_browser.hbs", 
		"URL={PVI_URL}/assets/pv/comp/templates/study_browser.hbs", 
		"Resource=1", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t103.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_add_auto_header("Accept", 
		"application/json, text/javascript, */*; q=0.01");

	web_url("getIngredients", 
		"URL={PVI_URL}/getIngredients?mapOfIds=%7B%7D&isSpecialField=true&_=1598531812921", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t104.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_auto_header("Accept", 
		"*/*");

	web_url("getActionViewList_2", 
		"URL={PVI_URL}/case/getActionViewList?pageId=4&templateId=3&_=1598531812922", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t105.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("FollowUp_04_NavigateDuplicateSearchScreen",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("FollowUp_05_SearchCases");

	web_add_auto_header("Origin", 
		"{PVI_URL}");

	web_add_auto_header("X-CSRF-TOKEN",
		"{TokenId2}");

	web_custom_request("saveState_3", 
		"URL={PVI_URL}/user/saveState", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t106.inf", 
		"Mode=HTTP", 
		"EncType=application/x-www-form-urlencoded; charset=UTF-8", 
		"Body=data=%7B%22form.duplicateSearchForm%3Etextarea.searchQuery%22%3A%22%22%2C%22form.duplicateSearchForm%3Eselect.safetyData.sourceType.id%22%3A%22%22%2C%22form.duplicateSearchForm%3Einput.safetyData.references%5B0%5D.id%22%3A%22{CreateAsFollowUp}%22%2C%22form.duplicateSearchForm%3Einput.safetyData.patient.name%22%3A%22%22%2C%22form.duplicateSearchForm%3Einput.safetyData.patient.age.value%3Aeq(0)%22%3A%22%22%2C%22form.duplicateSearchForm%3Ediv%3Aeq(0)%3Ediv%3Aeq(1)%3Ediv%3Ediv%3Aeq(5)"
		"%3Ediv%3Espan%3Espan%3Einput%22%3A%22unchecked%22%2C%22form.duplicateSearchForm%3Eselect.safetyData.patient.gender.id%22%3A%22%22%2C%22form.duplicateSearchForm%3Eselect.caseCountry.id%22%3A%22%22%2C%22form.duplicateSearchForm%3Einput%22%3A%22%22%2C%22form.duplicateSearchForm%3Einput.safetyData.events%5B0%5D.startDate.value%22%3A%22%22%2C%22form.duplicateSearchForm%3Einput.safetyData.reporters%5B0%5D.city%22%3A%22%22%2C%22form.duplicateSearchForm%3Einput.safetyData.reporters%5B0%5D.postcode%22%3A%2"
		"2%22%2C%22form.duplicateSearchForm%3Einput.safetyData.reporters%5B0%5D.telephone%22%3A%22%22%2C%22form.duplicateSearchForm%3Einput.safetyData.reporters%5B0%5D.faxNumber%22%3A%22%22%2C%22form.duplicateSearchForm%3Einput.safetyData.reporters%5B0%5D.email%22%3A%22%22%2C%22form.duplicateSearchForm%3Eselect.safetyData.reporters%5B0%5D.country.id%22%3A%22%22%2C%22form.duplicateSearchForm%3Eselect.date-range-type.persisting%22%3A%22firstReceiptDate%22%2C%22form.duplicateSearchForm%3Eselect.pviListDateRan"
		"ge.persisting%22%3A%22LAST_X_DAYS%22%2C%22form.duplicateSearchForm%3Einput.range-factor-field.persisting%22%3A%22365%22%2C%22form.duplicateSearchForm%3Einput.datepicker-rangeStartDate.persisting%22%3A%22%22%2C%22form.duplicateSearchForm%3Einput.datepicker-rangeEndDate.persisting%22%3A%22%22%2C%22form.duplicateSearchForm%3Ediv%3Aeq(1)%3Ediv%3Ediv%3Aeq(4)%3Ediv%3Ediv%3Aeq(0)%3Einput.persisting%22%3A%22checked%22%2C%22form.duplicateSearchForm%3Ediv%3Aeq(1)%3Ediv%3Ediv%3Aeq(4)%3Ediv%3Ediv%3Aeq(1)"
		"%3Einput.persisting%22%3A%22unchecked%22%2C%22form.duplicateSearchForm%3Ediv%3Aeq(1)%3Ediv%3Ediv%3Aeq(5)%3Ediv%3Aeq(1)%3Ediv%3Aeq(0)%3Einput.2-0%22%3A%22checked%22%2C%22form.duplicateSearchForm%3Ediv%3Aeq(1)%3Ediv%3Ediv%3Aeq(5)%3Ediv%3Aeq(1)%3Ediv%3Aeq(1)%3Einput.3-1%22%3A%22checked%22%2C%22form.duplicateSearchForm%3Ediv%3Aeq(1)%3Ediv%3Ediv%3Aeq(5)%3Ediv%3Aeq(1)%3Ediv%3Aeq(2)%3Einput.4-2%22%3A%22checked%22%2C%22form.duplicateSearchForm%3Ediv%3Aeq(1)%3Ediv%3Ediv%3Aeq(5)%3Ediv%3Aeq(1)%3Ediv%3Aeq(3)"
		"%3Einput.5-3%22%3A%22checked%22%2C%22form.duplicateSearchForm%3Ediv%3Aeq(1)%3Ediv%3Ediv%3Aeq(5)%3Ediv%3Aeq(1)%3Ediv%3Aeq(4)%3Einput.6-4%22%3A%22checked%22%2C%22form.duplicateSearchForm%3Ediv%3Aeq(1)%3Ediv%3Ediv%3Aeq(5)%3Ediv%3Aeq(1)%3Ediv%3Aeq(5)%3Einput.11-5%22%3A%22checked%22%7D&pageType=duplicateSearchForm&section=FORM_STATE", 
		LAST);

	web_reg_find("Search=Body",
		"Text={CreateAsFollowUp}",
		LAST);

	//244665
	web_reg_save_param_ex(
		"ParamName=CaseId",
		"LB=selected\":\"\",\"id\":",
		"RB=,\"intakeCaseNumber\"",
		SEARCH_FILTERS,
		LAST);

	
	web_submit_data("4_2", 
		"Action={PVI_URL}/case/rest/list/4", 
		"Method=POST", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t107.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=draw", "Value=3", ENDITEM, 
		"Name=columns[0][data]", "Value=selected", ENDITEM, 
		"Name=columns[0][name]", "Value=selected", ENDITEM, 
		"Name=columns[0][searchable]", "Value=true", ENDITEM, 
		"Name=columns[0][orderable]", "Value=false", ENDITEM, 
		"Name=columns[0][search][value]", "Value=", ENDITEM, 
		"Name=columns[0][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[1][data]", "Value=intakeCaseNumber", ENDITEM, 
		"Name=columns[1][name]", "Value=intakeCaseNumber", ENDITEM, 
		"Name=columns[1][searchable]", "Value=true", ENDITEM, 
		"Name=columns[1][orderable]", "Value=true", ENDITEM, 
		"Name=columns[1][search][value]", "Value=", ENDITEM, 
		"Name=columns[1][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[2][data]", "Value=mostRecentReceiptDateString", ENDITEM, 
		"Name=columns[2][name]", "Value=mostRecentReceiptDate", ENDITEM, 
		"Name=columns[2][searchable]", "Value=true", ENDITEM, 
		"Name=columns[2][orderable]", "Value=true", ENDITEM, 
		"Name=columns[2][search][value]", "Value=", ENDITEM, 
		"Name=columns[2][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[3][data]", "Value=sourceType", ENDITEM, 
		"Name=columns[3][name]", "Value=sourceType.type", ENDITEM, 
		"Name=columns[3][searchable]", "Value=true", ENDITEM, 
		"Name=columns[3][orderable]", "Value=true", ENDITEM, 
		"Name=columns[3][search][value]", "Value=", ENDITEM, 
		"Name=columns[3][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[4][data]", "Value=patientAge", ENDITEM, 
		"Name=columns[4][name]", "Value=patientAge", ENDITEM, 
		"Name=columns[4][searchable]", "Value=true", ENDITEM, 
		"Name=columns[4][orderable]", "Value=false", ENDITEM, 
		"Name=columns[4][search][value]", "Value=", ENDITEM, 
		"Name=columns[4][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[5][data]", "Value=gender", ENDITEM, 
		"Name=columns[5][name]", "Value=gender.value", ENDITEM, 
		"Name=columns[5][searchable]", "Value=true", ENDITEM, 
		"Name=columns[5][orderable]", "Value=true", ENDITEM, 
		"Name=columns[5][search][value]", "Value=", ENDITEM, 
		"Name=columns[5][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[6][data]", "Value=products", ENDITEM, 
		"Name=columns[6][name]", "Value=products.name", ENDITEM, 
		"Name=columns[6][searchable]", "Value=true", ENDITEM, 
		"Name=columns[6][orderable]", "Value=false", ENDITEM, 
		"Name=columns[6][search][value]", "Value=", ENDITEM, 
		"Name=columns[6][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[7][data]", "Value=patientName", ENDITEM, 
		"Name=columns[7][name]", "Value=patientName", ENDITEM, 
		"Name=columns[7][searchable]", "Value=true", ENDITEM, 
		"Name=columns[7][orderable]", "Value=true", ENDITEM, 
		"Name=columns[7][search][value]", "Value=", ENDITEM, 
		"Name=columns[7][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[8][data]", "Value=events", ENDITEM, 
		"Name=columns[8][name]", "Value=events.eventName", ENDITEM, 
		"Name=columns[8][searchable]", "Value=true", ENDITEM, 
		"Name=columns[8][orderable]", "Value=false", ENDITEM, 
		"Name=columns[8][search][value]", "Value=", ENDITEM, 
		"Name=columns[8][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[9][data]", "Value=seriousness", ENDITEM, 
		"Name=columns[9][name]", "Value=seriousnessString", ENDITEM, 
		"Name=columns[9][searchable]", "Value=true", ENDITEM, 
		"Name=columns[9][orderable]", "Value=false", ENDITEM, 
		"Name=columns[9][search][value]", "Value=", ENDITEM, 
		"Name=columns[9][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[10][data]", "Value=caseCountry", ENDITEM, 
		"Name=columns[10][name]", "Value=caseCountry.name", ENDITEM, 
		"Name=columns[10][searchable]", "Value=true", ENDITEM, 
		"Name=columns[10][orderable]", "Value=true", ENDITEM, 
		"Name=columns[10][search][value]", "Value=", ENDITEM, 
		"Name=columns[10][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[11][data]", "Value=allReferences", ENDITEM, 
		"Name=columns[11][name]", "Value=allReferences", ENDITEM, 
		"Name=columns[11][searchable]", "Value=true", ENDITEM, 
		"Name=columns[11][orderable]", "Value=false", ENDITEM, 
		"Name=columns[11][search][value]", "Value=", ENDITEM, 
		"Name=columns[11][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[12][data]", "Value=patientId", ENDITEM, 
		"Name=columns[12][name]", "Value=patientId", ENDITEM, 
		"Name=columns[12][searchable]", "Value=true", ENDITEM, 
		"Name=columns[12][orderable]", "Value=true", ENDITEM, 
		"Name=columns[12][search][value]", "Value=", ENDITEM, 
		"Name=columns[12][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[13][data]", "Value=dobString", ENDITEM, 
		"Name=columns[13][name]", "Value=dob", ENDITEM, 
		"Name=columns[13][searchable]", "Value=true", ENDITEM, 
		"Name=columns[13][orderable]", "Value=true", ENDITEM, 
		"Name=columns[13][search][value]", "Value=", ENDITEM, 
		"Name=columns[13][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[14][data]", "Value=matchScore", ENDITEM, 
		"Name=columns[14][name]", "Value=matchScore", ENDITEM, 
		"Name=columns[14][searchable]", "Value=true", ENDITEM, 
		"Name=columns[14][orderable]", "Value=true", ENDITEM, 
		"Name=columns[14][search][value]", "Value=", ENDITEM, 
		"Name=columns[14][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[15][data]", "Value=caseVersion", ENDITEM, 
		"Name=columns[15][name]", "Value=caseVersion", ENDITEM, 
		"Name=columns[15][searchable]", "Value=true", ENDITEM, 
		"Name=columns[15][orderable]", "Value=true", ENDITEM, 
		"Name=columns[15][search][value]", "Value=", ENDITEM, 
		"Name=columns[15][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[16][data]", "Value=firstReceiptDateString", ENDITEM, 
		"Name=columns[16][name]", "Value=firstReceiptDate", ENDITEM, 
		"Name=columns[16][searchable]", "Value=true", ENDITEM, 
		"Name=columns[16][orderable]", "Value=true", ENDITEM, 
		"Name=columns[16][search][value]", "Value=", ENDITEM, 
		"Name=columns[16][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[17][data]", "Value=reporterQualification", ENDITEM, 
		"Name=columns[17][name]", "Value=reporters.qualificationValue", ENDITEM, 
		"Name=columns[17][searchable]", "Value=true", ENDITEM, 
		"Name=columns[17][orderable]", "Value=true", ENDITEM, 
		"Name=columns[17][search][value]", "Value=", ENDITEM, 
		"Name=columns[17][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[18][data]", "Value=caseSeriousness", ENDITEM, 
		"Name=columns[18][name]", "Value=caseSeriousness.category", ENDITEM, 
		"Name=columns[18][searchable]", "Value=true", ENDITEM, 
		"Name=columns[18][orderable]", "Value=true", ENDITEM, 
		"Name=columns[18][search][value]", "Value=", ENDITEM, 
		"Name=columns[18][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[19][data]", "Value=priority", ENDITEM, 
		"Name=columns[19][name]", "Value=priority.value", ENDITEM, 
		"Name=columns[19][searchable]", "Value=true", ENDITEM, 
		"Name=columns[19][orderable]", "Value=true", ENDITEM, 
		"Name=columns[19][search][value]", "Value=", ENDITEM, 
		"Name=columns[19][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[20][data]", "Value=attachments", ENDITEM, 
		"Name=columns[20][name]", "Value=attachments.name", ENDITEM, 
		"Name=columns[20][searchable]", "Value=true", ENDITEM, 
		"Name=columns[20][orderable]", "Value=false", ENDITEM, 
		"Name=columns[20][search][value]", "Value=", ENDITEM, 
		"Name=columns[20][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[21][data]", "Value=dueDateString", ENDITEM, 
		"Name=columns[21][name]", "Value=dueDate", ENDITEM, 
		"Name=columns[21][searchable]", "Value=true", ENDITEM, 
		"Name=columns[21][orderable]", "Value=true", ENDITEM, 
		"Name=columns[21][search][value]", "Value=", ENDITEM, 
		"Name=columns[21][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[22][data]", "Value=isRelated", ENDITEM, 
		"Name=columns[22][name]", "Value=isRelated", ENDITEM, 
		"Name=columns[22][searchable]", "Value=true", ENDITEM, 
		"Name=columns[22][orderable]", "Value=true", ENDITEM, 
		"Name=columns[22][search][value]", "Value=", ENDITEM, 
		"Name=columns[22][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[23][data]", "Value=assignedToUsername", ENDITEM, 
		"Name=columns[23][name]", "Value=assignedToUsername", ENDITEM, 
		"Name=columns[23][searchable]", "Value=true", ENDITEM, 
		"Name=columns[23][orderable]", "Value=true", ENDITEM, 
		"Name=columns[23][search][value]", "Value=", ENDITEM, 
		"Name=columns[23][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[24][data]", "Value=safetyCaseNumber", ENDITEM, 
		"Name=columns[24][name]", "Value=safetyCaseNumber", ENDITEM, 
		"Name=columns[24][searchable]", "Value=true", ENDITEM, 
		"Name=columns[24][orderable]", "Value=true", ENDITEM, 
		"Name=columns[24][search][value]", "Value=", ENDITEM, 
		"Name=columns[24][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[25][data]", "Value=reportType", ENDITEM, 
		"Name=columns[25][name]", "Value=reportType", ENDITEM, 
		"Name=columns[25][searchable]", "Value=true", ENDITEM, 
		"Name=columns[25][orderable]", "Value=true", ENDITEM, 
		"Name=columns[25][search][value]", "Value=", ENDITEM, 
		"Name=columns[25][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[26][data]", "Value=destination", ENDITEM, 
		"Name=columns[26][name]", "Value=icsr.destination", ENDITEM, 
		"Name=columns[26][searchable]", "Value=true", ENDITEM, 
		"Name=columns[26][orderable]", "Value=true", ENDITEM, 
		"Name=columns[26][search][value]", "Value=", ENDITEM, 
		"Name=columns[26][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[27][data]", "Value=reportDueDateString", ENDITEM, 
		"Name=columns[27][name]", "Value=icsr.dueDate", ENDITEM, 
		"Name=columns[27][searchable]", "Value=true", ENDITEM, 
		"Name=columns[27][orderable]", "Value=true", ENDITEM, 
		"Name=columns[27][search][value]", "Value=", ENDITEM, 
		"Name=columns[27][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[28][data]", "Value=reporterComments", ENDITEM, 
		"Name=columns[28][name]", "Value=reporterComments", ENDITEM, 
		"Name=columns[28][searchable]", "Value=true", ENDITEM, 
		"Name=columns[28][orderable]", "Value=false", ENDITEM, 
		"Name=columns[28][search][value]", "Value=", ENDITEM, 
		"Name=columns[28][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[29][data]", "Value=reporters", ENDITEM, 
		"Name=columns[29][name]", "Value=reporters.name", ENDITEM, 
		"Name=columns[29][searchable]", "Value=true", ENDITEM, 
		"Name=columns[29][orderable]", "Value=true", ENDITEM, 
		"Name=columns[29][search][value]", "Value=", ENDITEM, 
		"Name=columns[29][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[30][data]", "Value=senderType", ENDITEM, 
		"Name=columns[30][name]", "Value=senderType.value", ENDITEM, 
		"Name=columns[30][searchable]", "Value=true", ENDITEM, 
		"Name=columns[30][orderable]", "Value=true", ENDITEM, 
		"Name=columns[30][search][value]", "Value=", ENDITEM, 
		"Name=columns[30][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[31][data]", "Value=senderName", ENDITEM, 
		"Name=columns[31][name]", "Value=senderName", ENDITEM, 
		"Name=columns[31][searchable]", "Value=true", ENDITEM, 
		"Name=columns[31][orderable]", "Value=true", ENDITEM, 
		"Name=columns[31][search][value]", "Value=", ENDITEM, 
		"Name=columns[31][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[32][data]", "Value=eventCountry", ENDITEM, 
		"Name=columns[32][name]", "Value=eventCountry.name", ENDITEM, 
		"Name=columns[32][searchable]", "Value=true", ENDITEM, 
		"Name=columns[32][orderable]", "Value=true", ENDITEM, 
		"Name=columns[32][search][value]", "Value=", ENDITEM, 
		"Name=columns[32][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[33][data]", "Value=reportVersion", ENDITEM, 
		"Name=columns[33][name]", "Value=icsr.reportVersion", ENDITEM, 
		"Name=columns[33][searchable]", "Value=true", ENDITEM, 
		"Name=columns[33][orderable]", "Value=true", ENDITEM, 
		"Name=columns[33][search][value]", "Value=", ENDITEM, 
		"Name=columns[33][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[34][data]", "Value=icsr", ENDITEM, 
		"Name=columns[34][name]", "Value=icsr.transmissionStatus", ENDITEM, 
		"Name=columns[34][searchable]", "Value=true", ENDITEM, 
		"Name=columns[34][orderable]", "Value=true", ENDITEM, 
		"Name=columns[34][search][value]", "Value=", ENDITEM, 
		"Name=columns[34][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[35][data]", "Value=stateTimestampString", ENDITEM, 
		"Name=columns[35][name]", "Value=icsr.stateTimestamp", ENDITEM, 
		"Name=columns[35][searchable]", "Value=true", ENDITEM, 
		"Name=columns[35][orderable]", "Value=true", ENDITEM, 
		"Name=columns[35][search][value]", "Value=", ENDITEM, 
		"Name=columns[35][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[36][data]", "Value=reportMessage", ENDITEM, 
		"Name=columns[36][name]", "Value=icsr.reportMessage", ENDITEM, 
		"Name=columns[36][searchable]", "Value=true", ENDITEM, 
		"Name=columns[36][orderable]", "Value=false", ENDITEM, 
		"Name=columns[36][search][value]", "Value=", ENDITEM, 
		"Name=columns[36][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[37][data]", "Value=eventName", ENDITEM, 
		"Name=columns[37][name]", "Value=eventName", ENDITEM, 
		"Name=columns[37][searchable]", "Value=true", ENDITEM, 
		"Name=columns[37][orderable]", "Value=true", ENDITEM, 
		"Name=columns[37][search][value]", "Value=", ENDITEM, 
		"Name=columns[37][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[38][data]", "Value=eventStartDate", ENDITEM, 
		"Name=columns[38][name]", "Value=eventStartDate", ENDITEM, 
		"Name=columns[38][searchable]", "Value=true", ENDITEM, 
		"Name=columns[38][orderable]", "Value=true", ENDITEM, 
		"Name=columns[38][search][value]", "Value=", ENDITEM, 
		"Name=columns[38][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[39][data]", "Value=outcome", ENDITEM, 
		"Name=columns[39][name]", "Value=outcome.value", ENDITEM, 
		"Name=columns[39][searchable]", "Value=true", ENDITEM, 
		"Name=columns[39][orderable]", "Value=true", ENDITEM, 
		"Name=columns[39][search][value]", "Value=", ENDITEM, 
		"Name=columns[39][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[40][data]", "Value=reporterCountry", ENDITEM, 
		"Name=columns[40][name]", "Value=reporters.countryName", ENDITEM, 
		"Name=columns[40][searchable]", "Value=true", ENDITEM, 
		"Name=columns[40][orderable]", "Value=true", ENDITEM, 
		"Name=columns[40][search][value]", "Value=", ENDITEM, 
		"Name=columns[40][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[41][data]", "Value=relatednessString", ENDITEM, 
		"Name=columns[41][name]", "Value=relatednessString", ENDITEM, 
		"Name=columns[41][searchable]", "Value=true", ENDITEM, 
		"Name=columns[41][orderable]", "Value=true", ENDITEM, 
		"Name=columns[41][search][value]", "Value=", ENDITEM, 
		"Name=columns[41][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[42][data]", "Value=categories", ENDITEM, 
		"Name=columns[42][name]", "Value=categories.value", ENDITEM, 
		"Name=columns[42][searchable]", "Value=true", ENDITEM, 
		"Name=columns[42][orderable]", "Value=false", ENDITEM, 
		"Name=columns[42][search][value]", "Value=", ENDITEM, 
		"Name=columns[42][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[43][data]", "Value=productName", ENDITEM, 
		"Name=columns[43][name]", "Value=productName", ENDITEM, 
		"Name=columns[43][searchable]", "Value=true", ENDITEM, 
		"Name=columns[43][orderable]", "Value=true", ENDITEM, 
		"Name=columns[43][search][value]", "Value=", ENDITEM, 
		"Name=columns[43][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[44][data]", "Value=substances", ENDITEM, 
		"Name=columns[44][name]", "Value=substances.nameValue", ENDITEM, 
		"Name=columns[44][searchable]", "Value=true", ENDITEM, 
		"Name=columns[44][orderable]", "Value=false", ENDITEM, 
		"Name=columns[44][search][value]", "Value=", ENDITEM, 
		"Name=columns[44][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[45][data]", "Value=studyNumber", ENDITEM, 
		"Name=columns[45][name]", "Value=studyNumber", ENDITEM, 
		"Name=columns[45][searchable]", "Value=true", ENDITEM, 
		"Name=columns[45][orderable]", "Value=true", ENDITEM, 
		"Name=columns[45][search][value]", "Value=", ENDITEM, 
		"Name=columns[45][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[46][data]", "Value=caseState", ENDITEM, 
		"Name=columns[46][name]", "Value=caseState", ENDITEM, 
		"Name=columns[46][searchable]", "Value=true", ENDITEM, 
		"Name=columns[46][orderable]", "Value=true", ENDITEM, 
		"Name=columns[46][search][value]", "Value=", ENDITEM, 
		"Name=columns[46][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[47][data]", "Value=versionType", ENDITEM, 
		"Name=columns[47][name]", "Value=versionType.value", ENDITEM, 
		"Name=columns[47][searchable]", "Value=true", ENDITEM, 
		"Name=columns[47][orderable]", "Value=true", ENDITEM, 
		"Name=columns[47][search][value]", "Value=", ENDITEM, 
		"Name=columns[47][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[48][data]", "Value=receiptDateString", ENDITEM, 
		"Name=columns[48][name]", "Value=receiptDate", ENDITEM, 
		"Name=columns[48][searchable]", "Value=true", ENDITEM, 
		"Name=columns[48][orderable]", "Value=false", ENDITEM, 
		"Name=columns[48][search][value]", "Value=", ENDITEM, 
		"Name=columns[48][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[49][data]", "Value=onsetDate", ENDITEM, 
		"Name=columns[49][name]", "Value=onsetDate", ENDITEM, 
		"Name=columns[49][searchable]", "Value=true", ENDITEM, 
		"Name=columns[49][orderable]", "Value=true", ENDITEM, 
		"Name=columns[49][search][value]", "Value=", ENDITEM, 
		"Name=columns[49][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[50][data]", "Value=submissionDate", ENDITEM, 
		"Name=columns[50][name]", "Value=submissionDate", ENDITEM, 
		"Name=columns[50][searchable]", "Value=true", ENDITEM, 
		"Name=columns[50][orderable]", "Value=true", ENDITEM, 
		"Name=columns[50][search][value]", "Value=", ENDITEM, 
		"Name=columns[50][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[51][data]", "Value=dosageForm", ENDITEM, 
		"Name=columns[51][name]", "Value=dosageForm.value", ENDITEM, 
		"Name=columns[51][searchable]", "Value=true", ENDITEM, 
		"Name=columns[51][orderable]", "Value=true", ENDITEM, 
		"Name=columns[51][search][value]", "Value=", ENDITEM, 
		"Name=columns[51][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[52][data]", "Value=caseVersionType", ENDITEM, 
		"Name=columns[52][name]", "Value=caseVersionType", ENDITEM, 
		"Name=columns[52][searchable]", "Value=true", ENDITEM, 
		"Name=columns[52][orderable]", "Value=true", ENDITEM, 
		"Name=columns[52][search][value]", "Value=", ENDITEM, 
		"Name=columns[52][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[53][data]", "Value=icsrType", ENDITEM, 
		"Name=columns[53][name]", "Value=icsr.type", ENDITEM, 
		"Name=columns[53][searchable]", "Value=true", ENDITEM, 
		"Name=columns[53][orderable]", "Value=true", ENDITEM, 
		"Name=columns[53][search][value]", "Value=", ENDITEM, 
		"Name=columns[53][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[54][data]", "Value=studyType", ENDITEM, 
		"Name=columns[54][name]", "Value=studyType.value", ENDITEM, 
		"Name=columns[54][searchable]", "Value=true", ENDITEM, 
		"Name=columns[54][orderable]", "Value=true", ENDITEM, 
		"Name=columns[54][search][value]", "Value=", ENDITEM, 
		"Name=columns[54][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[55][data]", "Value=simpleSearch", ENDITEM, 
		"Name=columns[55][name]", "Value=simpleSearch", ENDITEM, 
		"Name=columns[55][searchable]", "Value=true", ENDITEM, 
		"Name=columns[55][orderable]", "Value=true", ENDITEM, 
		"Name=columns[55][search][value]", "Value={\"allReferences\":\"{CreateAsFollowUp}\",\"caseStateId\":\"2,3,4,5,6,11\",\"config\":\"{\\\"isOrOperation\\\": \\\"true\\\", \\\"sortWhileSearch\\\": \\\"true\\\", \\\"countSearchCriteria\\\": \\\"true\\\"}\",\"isLatestValidVersion\":true,\"sourceDbId\":\"1\",\"firstReceiptDate\":\"{\\\"gte\\\":\\\"2019-08-29T00:00:00Z\\\",\\\"lte\\\":\\\"2020-08-27T23:59:59Z\\\"}\"}", ENDITEM, 
		"Name=columns[55][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[56][data]", "Value=dateRangeSearch", ENDITEM, 
		"Name=columns[56][name]", "Value=dateRangeSearch", ENDITEM, 
		"Name=columns[56][searchable]", "Value=true", ENDITEM, 
		"Name=columns[56][orderable]", "Value=true", ENDITEM, 
		"Name=columns[56][search][value]", "Value=", ENDITEM, 
		"Name=columns[56][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[57][data]", "Value=sourceDb", ENDITEM, 
		"Name=columns[57][name]", "Value=sourceDb", ENDITEM, 
		"Name=columns[57][searchable]", "Value=true", ENDITEM, 
		"Name=columns[57][orderable]", "Value=true", ENDITEM, 
		"Name=columns[57][search][value]", "Value=", ENDITEM, 
		"Name=columns[57][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[58][data]", "Value=safetyWFState", ENDITEM, 
		"Name=columns[58][name]", "Value=safetyWFState", ENDITEM, 
		"Name=columns[58][searchable]", "Value=true", ENDITEM, 
		"Name=columns[58][orderable]", "Value=true", ENDITEM, 
		"Name=columns[58][search][value]", "Value=", ENDITEM, 
		"Name=columns[58][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[59][data]", "Value=centralReceiptDateString", ENDITEM, 
		"Name=columns[59][name]", "Value=centralReceiptDate", ENDITEM, 
		"Name=columns[59][searchable]", "Value=true", ENDITEM, 
		"Name=columns[59][orderable]", "Value=true", ENDITEM, 
		"Name=columns[59][search][value]", "Value=", ENDITEM, 
		"Name=columns[59][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[60][data]", "Value=localSubmissionDateString", ENDITEM, 
		"Name=columns[60][name]", "Value=localSubmissionDate", ENDITEM, 
		"Name=columns[60][searchable]", "Value=true", ENDITEM, 
		"Name=columns[60][orderable]", "Value=true", ENDITEM, 
		"Name=columns[60][search][value]", "Value=", ENDITEM, 
		"Name=columns[60][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[61][data]", "Value=localSubmissionDueDateString", ENDITEM, 
		"Name=columns[61][name]", "Value=localSubmissionDueDate", ENDITEM, 
		"Name=columns[61][searchable]", "Value=true", ENDITEM, 
		"Name=columns[61][orderable]", "Value=true", ENDITEM, 
		"Name=columns[61][search][value]", "Value=", ENDITEM, 
		"Name=columns[61][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[62][data]", "Value=latestAssignmentComment", ENDITEM, 
		"Name=columns[62][name]", "Value=latestAssignmentComment", ENDITEM, 
		"Name=columns[62][searchable]", "Value=true", ENDITEM, 
		"Name=columns[62][orderable]", "Value=false", ENDITEM, 
		"Name=columns[62][search][value]", "Value=", ENDITEM, 
		"Name=columns[62][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[63][data]", "Value=vendor", ENDITEM, 
		"Name=columns[63][name]", "Value=vendor", ENDITEM, 
		"Name=columns[63][searchable]", "Value=true", ENDITEM, 
		"Name=columns[63][orderable]", "Value=true", ENDITEM, 
		"Name=columns[63][search][value]", "Value=", ENDITEM, 
		"Name=columns[63][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[64][data]", "Value=replacementRequired", ENDITEM, 
		"Name=columns[64][name]", "Value=replacementRequired", ENDITEM, 
		"Name=columns[64][searchable]", "Value=true", ENDITEM, 
		"Name=columns[64][orderable]", "Value=true", ENDITEM, 
		"Name=columns[64][search][value]", "Value=", ENDITEM, 
		"Name=columns[64][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[65][data]", "Value=caseCreatedDate", ENDITEM, 
		"Name=columns[65][name]", "Value=caseCreatedDate", ENDITEM, 
		"Name=columns[65][searchable]", "Value=true", ENDITEM, 
		"Name=columns[65][orderable]", "Value=true", ENDITEM, 
		"Name=columns[65][search][value]", "Value=", ENDITEM, 
		"Name=columns[65][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[66][data]", "Value=reporters", ENDITEM, 
		"Name=columns[66][name]", "Value=reporters.organization", ENDITEM, 
		"Name=columns[66][searchable]", "Value=true", ENDITEM, 
		"Name=columns[66][orderable]", "Value=true", ENDITEM, 
		"Name=columns[66][search][value]", "Value=", ENDITEM, 
		"Name=columns[66][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[67][data]", "Value=reporters", ENDITEM, 
		"Name=columns[67][name]", "Value=reporters.department", ENDITEM, 
		"Name=columns[67][searchable]", "Value=true", ENDITEM, 
		"Name=columns[67][orderable]", "Value=true", ENDITEM, 
		"Name=columns[67][search][value]", "Value=", ENDITEM, 
		"Name=columns[67][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[68][data]", "Value=reporters", ENDITEM, 
		"Name=columns[68][name]", "Value=reporters.address", ENDITEM, 
		"Name=columns[68][searchable]", "Value=true", ENDITEM, 
		"Name=columns[68][orderable]", "Value=true", ENDITEM, 
		"Name=columns[68][search][value]", "Value=", ENDITEM, 
		"Name=columns[68][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[69][data]", "Value=reporters", ENDITEM, 
		"Name=columns[69][name]", "Value=reporters.telephone", ENDITEM, 
		"Name=columns[69][searchable]", "Value=true", ENDITEM, 
		"Name=columns[69][orderable]", "Value=true", ENDITEM, 
		"Name=columns[69][search][value]", "Value=", ENDITEM, 
		"Name=columns[69][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[70][data]", "Value=reporters", ENDITEM, 
		"Name=columns[70][name]", "Value=reporters.faxNumber", ENDITEM, 
		"Name=columns[70][searchable]", "Value=true", ENDITEM, 
		"Name=columns[70][orderable]", "Value=true", ENDITEM, 
		"Name=columns[70][search][value]", "Value=", ENDITEM, 
		"Name=columns[70][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[71][data]", "Value=reporters", ENDITEM, 
		"Name=columns[71][name]", "Value=reporters.email", ENDITEM, 
		"Name=columns[71][searchable]", "Value=true", ENDITEM, 
		"Name=columns[71][orderable]", "Value=true", ENDITEM, 
		"Name=columns[71][search][value]", "Value=", ENDITEM, 
		"Name=columns[71][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[72][data]", "Value=pqcCaseNumber", ENDITEM, 
		"Name=columns[72][name]", "Value=pqcCaseNumber", ENDITEM, 
		"Name=columns[72][searchable]", "Value=true", ENDITEM, 
		"Name=columns[72][orderable]", "Value=true", ENDITEM, 
		"Name=columns[72][search][value]", "Value=", ENDITEM, 
		"Name=columns[72][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[73][data]", "Value=returnRequired", ENDITEM, 
		"Name=columns[73][name]", "Value=returnRequired", ENDITEM, 
		"Name=columns[73][searchable]", "Value=true", ENDITEM, 
		"Name=columns[73][orderable]", "Value=true", ENDITEM, 
		"Name=columns[73][search][value]", "Value=", ENDITEM, 
		"Name=columns[73][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[74][data]", "Value=refundRequested", ENDITEM, 
		"Name=columns[74][name]", "Value=refundRequested", ENDITEM, 
		"Name=columns[74][searchable]", "Value=true", ENDITEM, 
		"Name=columns[74][orderable]", "Value=true", ENDITEM, 
		"Name=columns[74][search][value]", "Value=", ENDITEM, 
		"Name=columns[74][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[75][data]", "Value=reporters", ENDITEM, 
		"Name=columns[75][name]", "Value=reporters.contactTypes.value", ENDITEM, 
		"Name=columns[75][searchable]", "Value=true", ENDITEM, 
		"Name=columns[75][orderable]", "Value=false", ENDITEM, 
		"Name=columns[75][search][value]", "Value=", ENDITEM, 
		"Name=columns[75][search][regex]", "Value=false", ENDITEM, 
		"Name=columns[76][data]", "Value=action", ENDITEM, 
		"Name=columns[76][name]", "Value=", ENDITEM, 
		"Name=columns[76][searchable]", "Value=true", ENDITEM, 
		"Name=columns[76][orderable]", "Value=false", ENDITEM, 
		"Name=columns[76][search][value]", "Value=", ENDITEM, 
		"Name=columns[76][search][regex]", "Value=false", ENDITEM, 
		"Name=start", "Value=0", ENDITEM, 
		"Name=length", "Value=10", ENDITEM, 
		"Name=search[value]", "Value=", ENDITEM, 
		"Name=search[regex]", "Value=false", ENDITEM, 
		"Name=caseIdAvailable", "Value=", ENDITEM, 
		"Name=loadData", "Value=true", ENDITEM, 
		LAST);

	web_submit_data("saveState_4", 
		"Action={PVI_URL}/user/saveState", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t108.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=data", "Value={\"time\":1598531878059,\"start\":0,\"length\":10,\"order\":[],\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true},\"columns\":[{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\""
		"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\""
		"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\""
		"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\""
		"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\""
		"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\""
		"search\":\"{\\\"allReferences\\\":\\\"{CreateAsFollowUp}\\\",\\\"caseStateId\\\":\\\"2,3,4,5,6,11\\\",\\\"config\\\":\\\"{\\\\\\\"isOrOperation\\\\\\\": \\\\\\\"true\\\\\\\", \\\\\\\"sortWhileSearch\\\\\\\": \\\\\\\"true\\\\\\\", \\\\\\\"countSearchCriteria\\\\\\\": \\\\\\\"true\\\\\\\"}\\\",\\\"isLatestValidVersion\\\":true,\\\"sourceDbId\\\":\\\"1\\\",\\\"firstReceiptDate\\\":\\\"{\\\\\\\"gte\\\\\\\":\\\\\\\"2019-08-29T00:00:00Z\\\\\\\",\\\\\\\"lte\\\\\\\":\\\\\\\"2020-08-27T23:59:59Z\\\\\\\"}\\\"}\","
		"\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\""
		"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}"
		"},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}}],\"ColReorder\":[0,1,35,33,15,16,6,48,5,49,50,51,52,53,54,2,3,4,7,8,9,10,11,12,13,14,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,34,36,37,38,39,40,41,42,43,44,45,46,47,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76]}", ENDITEM, 
		"Name=pageType", "Value=duplicateSearchForm", ENDITEM, 
		"Name=section", "Value=DataTable", ENDITEM, 
		LAST);

	lr_end_transaction("FollowUp_05_SearchCases",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("FollowUp_06_CreateAsFollowUp");

	web_submit_data("checkEditLock", 
		"Action={PVI_URL}/caseEntry/checkEditLock", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t109.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=data", "Value={\"caseId\":{CaseId}}", ENDITEM, 
		LAST);

	//case-id":"244691"
	web_reg_save_param_ex(
		"ParamName=CaseId_3",
		"LB=case-id\":\"",
		"RB=\"",
		SEARCH_FILTERS,
		"Scope=ALL",
		LAST);

	web_reg_find("Search=Body",
		"Text=created successfully",
		LAST);

	web_submit_data("createFollowUp", 
		"Action={PVI_URL}/caseEntry/createFollowUp/", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t110.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=data", "Value={\"initialCaseId\":{CreateAsFollowUp},\"accept\":true,\"safetyCaseNum\":\"\"}", ENDITEM, 
		LAST);

	web_revert_auto_header("Origin");

	web_revert_auto_header("X-CSRF-TOKEN");

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("Accept", 
		"text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("{CaseId_3}", 
		"URL={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t111.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_start(NULL);

	web_url("case-entry-manifest-0691008e616302be087a77f0c4f6bc2a.css", 
		"URL={PVI_URL}/assets/app/case-entry/case-entry-manifest-0691008e616302be087a77f0c4f6bc2a.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Snapshot=t112.inf", 
		LAST);

	web_url("case-entry-manifest-326b4b6f7e313829e23e4a6c86b40dfb.js", 
		"URL={PVI_URL}/assets/app/case-entry/case-entry-manifest-326b4b6f7e313829e23e4a6c86b40dfb.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Snapshot=t113.inf", 
		LAST);

//	web_concurrent_end(NULL);
//
//	web_add_auto_header("Accept", 
//		"*/*");
//
//	web_add_auto_header("X-Requested-With", 
//		"XMLHttpRequest");

	web_url("en-US.json_3", 
		"URL={PVI_URL}/assets/vendor/documentViewerJson/en-US.json?_=1598531906499", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Snapshot=t114.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("predefinedSearch.json_3", 
		"URL={PVI_URL}/assets/vendor/documentViewerJson/predefinedSearch.json?_=1598531906500", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Snapshot=t115.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("downloadOverlayTemplate.html_3", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/downloadOverlayTemplate.html?_=1598531906505", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Snapshot=t116.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("redactionReason.json_3", 
		"URL={PVI_URL}/assets/vendor/documentViewerJson/redactionReason.json?_=1598531906501", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Snapshot=t117.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("esignOverlayTemplate.html_3", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/esignOverlayTemplate.html?_=1598531906506", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Snapshot=t118.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("hyperlinkMenuTemplate.html_3", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/hyperlinkMenuTemplate.html?_=1598531906507", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Snapshot=t119.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("imageStampOverlayTemplate.html_3", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/imageStampOverlayTemplate.html?_=1598531906508", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Snapshot=t120.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("overwriteOverlayTemplate.html_3", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/overwriteOverlayTemplate.html?_=1598531906509", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Snapshot=t121.inf", 
		"Mode=HTTP", 
		LAST);

//	web_add_auto_header("Accept", 
//		"application/json, text/javascript, */*; q=0.01");

	web_url("loadServerTime_3", 
		"URL={PVI_URL}/config/loadServerTime?_=1598531906516", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Snapshot=t122.inf", 
		"Mode=HTTP", 
		LAST);

//	web_add_auto_header("Accept", 
//		"*/*");

	web_url("copyOverlayTemplate.html_3", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/copyOverlayTemplate.html?_=1598531906504", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Snapshot=t123.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("contextMenuTemplate.html_3", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/contextMenuTemplate.html?_=1598531906503", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Snapshot=t124.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("pageRedactionOverlayTemplate.html_3", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/pageRedactionOverlayTemplate.html?_=1598531906510", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Snapshot=t125.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("printOverlayTemplate.html_3", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/printOverlayTemplate.html?_=1598531906511", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Snapshot=t126.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("redactionReasonTemplate.html_3", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/redactionReasonTemplate.html?_=1598531906513", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Snapshot=t127.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("printTemplate.html_3", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/printTemplate.html?_=1598531906512", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Snapshot=t128.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("unsavedChangesOverlayTemplate.html_3", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/unsavedChangesOverlayTemplate.html?_=1598531906514", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Snapshot=t129.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("viewerTemplate.html_3", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/viewerTemplate.html?_=1598531906515", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Snapshot=t130.inf", 
		"Mode=HTTP", 
		LAST);

//	web_add_auto_header("Accept", 
//		"application/json, text/javascript, */*; q=0.01");

	web_url("getIngredients_2", 
		"URL={PVI_URL}/getIngredients?mapOfIds=%7B%220%22%3A%5B3539%5D%2C%221%22%3A%5B10260101%5D%2C%222%22%3A%5B3539%5D%2C%223%22%3A%5B10349701%5D%2C%224%22%3A%5B2330%5D%7D&isSpecialField=true&_=1598531906517", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Snapshot=t131.inf", 
		"Mode=HTTP", 
		LAST);

//	web_add_auto_header("Accept", 
//		"*/*");

	web_url("fetchAllUser", 
		"URL={PVI_URL}/user/fetchAllUser?_=1598531906518", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Snapshot=t132.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("getKaseMedDraHierarchyStored", 
		"URL={PVI_URL}/case/getKaseMedDraHierarchyStored?id={CaseId_3}&_=1598531906519", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Snapshot=t133.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("getActionViewList_3", 
		"URL={PVI_URL}/case/getActionViewList?pageId=3&templateId=1&sourceDbId=1&_=1598531906520", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Snapshot=t134.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("commentTemplate.html_3", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/commentTemplate.html?_=1598531906502", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Snapshot=t135.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("fetchAllTemplates", 
		"URL={PVI_URL}/caseEntry/fetchAllTemplates?templateId=1", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/caseEntry/show/{CaseId_3}?templateId=1", 
		"Snapshot=t136.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_end(NULL);

	lr_end_transaction("FollowUp_06_CreateAsFollowUp",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("FollowUp_07_Back");
	
	web_concurrent_start(NULL);

	web_url("redactionReason.json_4", 
		"URL={PVI_URL}/assets/vendor/documentViewerJson/redactionReason.json?_=1598531934186", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t137.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("commentTemplate.html_4", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/commentTemplate.html?_=1598531934187", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t138.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("predefinedSearch.json_4", 
		"URL={PVI_URL}/assets/vendor/documentViewerJson/predefinedSearch.json?_=1598531934185", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t139.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("en-US.json_4", 
		"URL={PVI_URL}/assets/vendor/documentViewerJson/en-US.json?_=1598531934184", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t140.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("copyOverlayTemplate.html_4", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/copyOverlayTemplate.html?_=1598531934189", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t141.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("contextMenuTemplate.html_4", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/contextMenuTemplate.html?_=1598531934188", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t142.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("downloadOverlayTemplate.html_4", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/downloadOverlayTemplate.html?_=1598531934190", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t143.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("esignOverlayTemplate.html_4", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/esignOverlayTemplate.html?_=1598531934191", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t144.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("imageStampOverlayTemplate.html_4", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/imageStampOverlayTemplate.html?_=1598531934193", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t145.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("overwriteOverlayTemplate.html_4", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/overwriteOverlayTemplate.html?_=1598531934194", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t146.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("hyperlinkMenuTemplate.html_4", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/hyperlinkMenuTemplate.html?_=1598531934192", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t147.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("getActionViewList_4", 
		"URL={PVI_URL}/case/getActionViewList?pageId=4&templateId=3&_=1598531934203", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t148.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("printTemplate.html_4", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/printTemplate.html?_=1598531934197", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t149.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("printOverlayTemplate.html_4", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/printOverlayTemplate.html?_=1598531934196", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t150.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("pageRedactionOverlayTemplate.html_4", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/pageRedactionOverlayTemplate.html?_=1598531934195", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t151.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("unsavedChangesOverlayTemplate.html_4", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/unsavedChangesOverlayTemplate.html?_=1598531934199", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t152.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("redactionReasonTemplate.html_4", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/redactionReasonTemplate.html?_=1598531934198", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t153.inf", 
		"Mode=HTTP", 
		LAST);

//	web_add_auto_header("Accept", 
//		"application/json, text/javascript, */*; q=0.01");

	web_url("getIngredients_3", 
		"URL={PVI_URL}/getIngredients?mapOfIds=%7B%7D&isSpecialField=true&_=1598531934202", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t154.inf", 
		"Mode=HTTP", 
		LAST);

//	web_add_auto_header("Accept", 
//		"*/*");

	web_url("4_3", 
		"URL={PVI_URL}/case/rest/list_columns/4?_=1598531934201", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t155.inf", 
		"Mode=HTTP", 
		LAST);

//	web_add_auto_header("Accept", 
//		"application/json, text/javascript, */*; q=0.01");

	web_url("loadServerTime_4", 
		"URL={PVI_URL}/config/loadServerTime?_=1598531934204", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t156.inf", 
		"Mode=HTTP", 
		LAST);

//	web_add_auto_header("Accept", 
//		"*/*");

	web_url("viewerTemplate.html_4", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/viewerTemplate.html?_=1598531934200", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t157.inf", 
		"Mode=HTTP", 
		LAST);
	
	web_concurrent_end(NULL);

	web_add_auto_header("Origin", 
		"{PVI_URL}");

	web_add_auto_header("X-CSRF-TOKEN",
		"{TokenId2}");

	web_submit_data("saveState_5", 
		"Action={PVI_URL}/user/saveState", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t158.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=data", "Value={\"time\":1598531936479,\"start\":0,\"length\":10,\"order\":[],\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true},\"columns\":[{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\""
		"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\""
		"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\""
		"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\""
		"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\""
		"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\""
		"search\":\"{\\\"allReferences\\\":\\\"{CreateAsFollowUp}\\\",\\\"caseStateId\\\":\\\"2,3,4,5,6,11\\\",\\\"config\\\":\\\"{\\\\\\\"isOrOperation\\\\\\\": \\\\\\\"true\\\\\\\", \\\\\\\"sortWhileSearch\\\\\\\": \\\\\\\"true\\\\\\\", \\\\\\\"countSearchCriteria\\\\\\\": \\\\\\\"true\\\\\\\"}\\\",\\\"isLatestValidVersion\\\":true,\\\"sourceDbId\\\":\\\"1\\\",\\\"firstReceiptDate\\\":\\\"{\\\\\\\"gte\\\\\\\":\\\\\\\"2019-08-29T00:00:00Z\\\\\\\",\\\\\\\"lte\\\\\\\":\\\\\\\"2020-08-27T23:59:59Z\\\\\\\"}\\\"}\","
		"\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\""
		"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}"
		"},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}}],\"ColReorder\":[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76]}", ENDITEM, 
		"Name=pageType", "Value=duplicateSearchForm", ENDITEM, 
		"Name=section", "Value=DataTable", ENDITEM, 
		LAST);

	web_submit_data("saveState_6", 
		"Action={PVI_URL}/user/saveState", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t159.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=data", "Value={\"time\":1598531936569,\"start\":0,\"length\":10,\"order\":[],\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true},\"columns\":[{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\""
		"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\""
		"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\""
		"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\""
		"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\""
		"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\""
		"search\":\"{\\\"allReferences\\\":\\\"{CreateAsFollowUp}\\\",\\\"caseStateId\\\":\\\"2,3,4,5,6,11\\\",\\\"config\\\":\\\"{\\\\\\\"isOrOperation\\\\\\\": \\\\\\\"true\\\\\\\", \\\\\\\"sortWhileSearch\\\\\\\": \\\\\\\"true\\\\\\\", \\\\\\\"countSearchCriteria\\\\\\\": \\\\\\\"true\\\\\\\"}\\\",\\\"isLatestValidVersion\\\":true,\\\"sourceDbId\\\":\\\"1\\\",\\\"firstReceiptDate\\\":\\\"{\\\\\\\"gte\\\\\\\":\\\\\\\"2019-08-29T00:00:00Z\\\\\\\",\\\\\\\"lte\\\\\\\":\\\\\\\"2020-08-27T23:59:59Z\\\\\\\"}\\\"}\","
		"\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\""
		"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}"
		"},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}}],\"ColReorder\":[0,1,35,33,15,16,6,48,5,49,50,51,52,53,54,2,3,4,7,8,9,10,11,12,13,14,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,34,36,37,38,39,40,41,42,43,44,45,46,47,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76]}", ENDITEM, 
		"Name=pageType", "Value=duplicateSearchForm", ENDITEM, 
		"Name=section", "Value=DataTable", ENDITEM, 
		LAST);

	lr_end_transaction("FollowUp_07_Back",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("FollowUp_08_NewFollowUp");

	lr_end_transaction("FollowUp_08_NewFollowUp",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("FollowUp_09_EnterCaseNumberAndClickOkFU");

/*Correlation comment - Do not change!  Original value='244692' Name ='CaseId_2' Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=CaseId_2",
		"LB={\"case-id\":\"",
		"RB=\"",
		SEARCH_FILTERS,
		"Scope=Body",
		LAST);

	web_reg_find("Search=Body",
		"Text=created successfully",
		LAST);

	web_submit_data("createFollowUp_2", 
		"Action={PVI_URL}/caseEntry/createFollowUp/", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t160.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=data", "Value={\"initialCaseId\":\"{New_FU}\",\"accept\":false}", ENDITEM, 
		LAST);

	web_revert_auto_header("Origin");

	web_revert_auto_header("X-CSRF-TOKEN");

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("Accept", 
		"text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("244692",
		"URL={PVI_URL}/caseEntry/show/{CaseId_2}?templateId=1",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={PVI_URL}/duplicate/search",
		"Snapshot=t161.inf",
		"Mode=HTTP",
		LAST);

	web_add_header("If-None-Match", 
		"\"vendor/spinner-c7b3cbb3ec8249a7121b722cdd76b870.gif\"");

	web_url("spinner.gif",
		"URL={PVI_URL}/assets/vendor/spinner.gif",
		"Resource=1",
		"Referer={PVI_URL}/caseEntry/show/{CaseId_2}?templateId=1",
		"Snapshot=t162.inf",
		LAST);

	web_add_auto_header("Accept", 
		"*/*");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_concurrent_start(NULL);
	web_url("en-US.json_5",
		"URL={PVI_URL}/assets/vendor/documentViewerJson/en-US.json?_=1598531975928",
		"Resource=0",
		"RecContentType=application/json",
		"Referer={PVI_URL}/caseEntry/show/{CaseId_2}?templateId=1",
		"Snapshot=t163.inf",
		"Mode=HTTP",
		LAST);

	web_url("predefinedSearch.json_5",
		"URL={PVI_URL}/assets/vendor/documentViewerJson/predefinedSearch.json?_=1598531975929",
		"Resource=0",
		"RecContentType=application/json",
		"Referer={PVI_URL}/caseEntry/show/{CaseId_2}?templateId=1",
		"Snapshot=t164.inf",
		"Mode=HTTP",
		LAST);

	web_url("commentTemplate.html_5",
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/commentTemplate.html?_=1598531975931",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={PVI_URL}/caseEntry/show/{CaseId_2}?templateId=1",
		"Snapshot=t165.inf",
		"Mode=HTTP",
		LAST);

	web_url("copyOverlayTemplate.html_5",
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/copyOverlayTemplate.html?_=1598531975933",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={PVI_URL}/caseEntry/show/{CaseId_2}?templateId=1",
		"Snapshot=t166.inf",
		"Mode=HTTP",
		LAST);

	web_url("redactionReason.json_5",
		"URL={PVI_URL}/assets/vendor/documentViewerJson/redactionReason.json?_=1598531975930",
		"Resource=0",
		"RecContentType=application/json",
		"Referer={PVI_URL}/caseEntry/show/{CaseId_2}?templateId=1",
		"Snapshot=t167.inf",
		"Mode=HTTP",
		LAST);

	web_url("downloadOverlayTemplate.html_5",
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/downloadOverlayTemplate.html?_=1598531975934",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={PVI_URL}/caseEntry/show/{CaseId_2}?templateId=1",
		"Snapshot=t168.inf",
		"Mode=HTTP",
		LAST);

	web_url("imageStampOverlayTemplate.html_5",
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/imageStampOverlayTemplate.html?_=1598531975937",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={PVI_URL}/caseEntry/show/{CaseId_2}?templateId=1",
		"Snapshot=t169.inf",
		"Mode=HTTP",
		LAST);

	web_url("overwriteOverlayTemplate.html_5",
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/overwriteOverlayTemplate.html?_=1598531975938",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={PVI_URL}/caseEntry/show/{CaseId_2}?templateId=1",
		"Snapshot=t170.inf",
		"Mode=HTTP",
		LAST);

	web_url("esignOverlayTemplate.html_5",
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/esignOverlayTemplate.html?_=1598531975935",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={PVI_URL}/caseEntry/show/{CaseId_2}?templateId=1",
		"Snapshot=t171.inf",
		"Mode=HTTP",
		LAST);

	

	web_url("pageRedactionOverlayTemplate.html_5",
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/pageRedactionOverlayTemplate.html?_=1598531975939",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={PVI_URL}/caseEntry/show/{CaseId_2}?templateId=1",
		"Snapshot=t173.inf",
		"Mode=HTTP",
		LAST);

	web_url("printOverlayTemplate.html_5",
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/printOverlayTemplate.html?_=1598531975940",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={PVI_URL}/caseEntry/show/{CaseId_2}?templateId=1",
		"Snapshot=t174.inf",
		"Mode=HTTP",
		LAST);

	web_url("printTemplate.html_5",
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/printTemplate.html?_=1598531975941",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={PVI_URL}/caseEntry/show/{CaseId_2}?templateId=1",
		"Snapshot=t175.inf",
		"Mode=HTTP",
		LAST);

	web_url("redactionReasonTemplate.html_5",
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/redactionReasonTemplate.html?_=1598531975942",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={PVI_URL}/caseEntry/show/{CaseId_2}?templateId=1",
		"Snapshot=t176.inf",
		"Mode=HTTP",
		LAST);

	web_url("unsavedChangesOverlayTemplate.html_5",
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/unsavedChangesOverlayTemplate.html?_=1598531975943",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={PVI_URL}/caseEntry/show/{CaseId_2}?templateId=1",
		"Snapshot=t177.inf",
		"Mode=HTTP",
		LAST);

	web_url("hyperlinkMenuTemplate.html_5",
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/hyperlinkMenuTemplate.html?_=1598531975936",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={PVI_URL}/caseEntry/show/{CaseId_2}?templateId=1",
		"Snapshot=t178.inf",
		"Mode=HTTP",
		LAST);

	web_url("viewerTemplate.html_5",
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/viewerTemplate.html?_=1598531975944",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={PVI_URL}/caseEntry/show/{CaseId_2}?templateId=1",
		"Snapshot=t179.inf",
		"Mode=HTTP",
		LAST);

//	web_add_auto_header("Accept", 
//		"application/json, text/javascript, */*; q=0.01");

	web_url("loadServerTime_5",
		"URL={PVI_URL}/config/loadServerTime?_=1598531975945",
		"Resource=0",
		"RecContentType=application/json",
		"Referer={PVI_URL}/caseEntry/show/{CaseId_2}?templateId=1",
		"Snapshot=t180.inf",
		"Mode=HTTP",
		LAST);

	web_url("getIngredients_4",
		"URL={PVI_URL}/getIngredients?mapOfIds=%7B%220%22%3A%5B3539%5D%2C%221%22%3A%5B10260101%5D%2C%222%22%3A%5B3539%5D%2C%223%22%3A%5B10349701%5D%2C%224%22%3A%5B2330%5D%7D&isSpecialField=true&_=1598531975946",
		"Resource=0",
		"RecContentType=application/json",
		"Referer={PVI_URL}/caseEntry/show/{CaseId_2}?templateId=1",
		"Snapshot=t181.inf",
		"Mode=HTTP",
		LAST);

//	web_add_auto_header("Accept", 
//		"*/*");

	web_url("fetchAllUser_2",
		"URL={PVI_URL}/user/fetchAllUser?_=1598531975947",
		"Resource=0",
		"RecContentType=application/json",
		"Referer={PVI_URL}/caseEntry/show/{CaseId_2}?templateId=1",
		"Snapshot=t182.inf",
		"Mode=HTTP",
		LAST);

	web_url("getKaseMedDraHierarchyStored_2",
		"URL={PVI_URL}/case/getKaseMedDraHierarchyStored?id={CaseId_2}&_=1598531975948",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={PVI_URL}/caseEntry/show/{CaseId_2}?templateId=1",
		"Snapshot=t183.inf",
		"Mode=HTTP",
		LAST);

	web_url("getActionViewList_5",
		"URL={PVI_URL}/case/getActionViewList?pageId=3&templateId=1&sourceDbId=1&_=1598531975949",
		"Resource=0",
		"RecContentType=application/json",
		"Referer={PVI_URL}/caseEntry/show/{CaseId_2}?templateId=1",
		"Snapshot=t184.inf",
		"Mode=HTTP",
		LAST);

	web_url("contextMenuTemplate.html_5",
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/contextMenuTemplate.html?_=1598531975932",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={PVI_URL}/caseEntry/show/{CaseId_2}?templateId=1",
		"Snapshot=t185.inf",
		"Mode=HTTP",
		LAST);

	web_url("fetchAllTemplates_2",
		"URL={PVI_URL}/caseEntry/fetchAllTemplates?templateId=1",
		"Resource=0",
		"RecContentType=text/html",
		"Referer={PVI_URL}/caseEntry/show/{CaseId_2}?templateId=1",
		"Snapshot=t186.inf",
		"Mode=HTTP",
		LAST);

	web_concurrent_end(NULL);
	
	lr_end_transaction("FollowUp_09_EnterCaseNumberAndClickOkFU",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("FollowUp_10_ClickBack");
	
	web_concurrent_start(NULL);

	web_url("predefinedSearch.json_6", 
		"URL={PVI_URL}/assets/vendor/documentViewerJson/predefinedSearch.json?_=1598532002618", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t187.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("redactionReason.json_6", 
		"URL={PVI_URL}/assets/vendor/documentViewerJson/redactionReason.json?_=1598532002619", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t188.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("contextMenuTemplate.html_6", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/contextMenuTemplate.html?_=1598532002621", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t189.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("en-US.json_6", 
		"URL={PVI_URL}/assets/vendor/documentViewerJson/en-US.json?_=1598532002617", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t190.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("copyOverlayTemplate.html_6", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/copyOverlayTemplate.html?_=1598532002622", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t191.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("imageStampOverlayTemplate.html_6", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/imageStampOverlayTemplate.html?_=1598532002626", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t192.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("hyperlinkMenuTemplate.html_6", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/hyperlinkMenuTemplate.html?_=1598532002625", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t193.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("downloadOverlayTemplate.html_6", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/downloadOverlayTemplate.html?_=1598532002623", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t194.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("esignOverlayTemplate.html_6", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/esignOverlayTemplate.html?_=1598532002624", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t195.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("getActionViewList_6", 
		"URL={PVI_URL}/case/getActionViewList?pageId=4&templateId=3&_=1598532002636", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t196.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("overwriteOverlayTemplate.html_6", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/overwriteOverlayTemplate.html?_=1598532002627", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t197.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("printOverlayTemplate.html_6", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/printOverlayTemplate.html?_=1598532002629", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t198.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("pageRedactionOverlayTemplate.html_6", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/pageRedactionOverlayTemplate.html?_=1598532002628", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t199.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("redactionReasonTemplate.html_6", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/redactionReasonTemplate.html?_=1598532002631", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t200.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("printTemplate.html_6", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/printTemplate.html?_=1598532002630", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t201.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("viewerTemplate.html_6", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/viewerTemplate.html?_=1598532002633", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t202.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("unsavedChangesOverlayTemplate.html_6", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/unsavedChangesOverlayTemplate.html?_=1598532002632", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t203.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("4_4", 
		"URL={PVI_URL}/case/rest/list_columns/4?_=1598532002634", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t204.inf", 
		"Mode=HTTP", 
		LAST);

//	web_add_auto_header("Accept", 
//		"application/json, text/javascript, */*; q=0.01");

	web_url("getIngredients_5", 
		"URL={PVI_URL}/getIngredients?mapOfIds=%7B%7D&isSpecialField=true&_=1598532002635", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t205.inf", 
		"Mode=HTTP", 
		LAST);

	web_url("loadServerTime_6", 
		"URL={PVI_URL}/config/loadServerTime?_=1598532002637", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t206.inf", 
		"Mode=HTTP", 
		LAST);
	
	web_concurrent_end(NULL);

	web_add_auto_header("Accept", 
		"*/*");

	web_add_auto_header("Origin", 
		"{PVI_URL}");

	web_add_auto_header("X-CSRF-TOKEN",
		"{TokenId2}");

	web_submit_data("saveState_7", 
		"Action={PVI_URL}/user/saveState", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t207.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=data", "Value={\"time\":1598532005751,\"start\":0,\"length\":10,\"order\":[],\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true},\"columns\":[{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\""
		"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\""
		"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\""
		"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\""
		"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\""
		"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\""
		"search\":\"{\\\"allReferences\\\":\\\"{CreateAsFollowUp}\\\",\\\"caseStateId\\\":\\\"2,3,4,5,6,11\\\",\\\"config\\\":\\\"{\\\\\\\"isOrOperation\\\\\\\": \\\\\\\"true\\\\\\\", \\\\\\\"sortWhileSearch\\\\\\\": \\\\\\\"true\\\\\\\", \\\\\\\"countSearchCriteria\\\\\\\": \\\\\\\"true\\\\\\\"}\\\",\\\"isLatestValidVersion\\\":true,\\\"sourceDbId\\\":\\\"1\\\",\\\"firstReceiptDate\\\":\\\"{\\\\\\\"gte\\\\\\\":\\\\\\\"2019-08-29T00:00:00Z\\\\\\\",\\\\\\\"lte\\\\\\\":\\\\\\\"2020-08-27T23:59:59Z\\\\\\\"}\\\"}\","
		"\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\""
		"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}"
		"},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}}],\"ColReorder\":[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76]}", ENDITEM, 
		"Name=pageType", "Value=duplicateSearchForm", ENDITEM, 
		"Name=section", "Value=DataTable", ENDITEM, 
		LAST);

	web_submit_data("saveState_8", 
		"Action={PVI_URL}/user/saveState", 
		"Method=POST", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t208.inf", 
		"Mode=HTTP", 
		ITEMDATA, 
		"Name=data", "Value={\"time\":1598532005843,\"start\":0,\"length\":10,\"order\":[],\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true},\"columns\":[{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\""
		"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\""
		"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\""
		"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\""
		"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\""
		"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\""
		"search\":\"{\\\"allReferences\\\":\\\"{CreateAsFollowUp}\\\",\\\"caseStateId\\\":\\\"2,3,4,5,6,11\\\",\\\"config\\\":\\\"{\\\\\\\"isOrOperation\\\\\\\": \\\\\\\"true\\\\\\\", \\\\\\\"sortWhileSearch\\\\\\\": \\\\\\\"true\\\\\\\", \\\\\\\"countSearchCriteria\\\\\\\": \\\\\\\"true\\\\\\\"}\\\",\\\"isLatestValidVersion\\\":true,\\\"sourceDbId\\\":\\\"1\\\",\\\"firstReceiptDate\\\":\\\"{\\\\\\\"gte\\\\\\\":\\\\\\\"2019-08-29T00:00:00Z\\\\\\\",\\\\\\\"lte\\\\\\\":\\\\\\\"2020-08-27T23:59:59Z\\\\\\\"}\\\"}\","
		"\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\""
		"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}"
		"},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\""
		"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\""
		":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":false,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}},{\"visible\":true,\"search\":{\"search\":\"\",\"smart\":true,\"regex\":false,\"caseInsensitive\":true}}],\"ColReorder\":[0,1,35,33,15,16,6,48,5,49,50,51,52,53,54,2,3,4,7,8,9,10,11,12,13,14,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,34,36,37,38,39,40,41,42,43,44,45,46,47,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76]}", ENDITEM, 
		"Name=pageType", "Value=duplicateSearchForm", ENDITEM, 
		"Name=section", "Value=DataTable", ENDITEM, 
		LAST);

	web_revert_auto_header("Origin");

	web_revert_auto_header("X-CSRF-TOKEN");

	web_url("commentTemplate.html_6", 
		"URL={PVI_URL}/assets/vendor/documentViewerTemplates/commentTemplate.html?_=1598532002620", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t209.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("FollowUp_10_ClickBack",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("FollowUp_11_NavigatePVAdmin");

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("Accept", 
		"text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_reg_find("Search=Body",
		"Text=Welcome to PV Admin",
		LAST);

	web_url("10.100.22.34:8083", 
		"URL={PV_Admin_URL}/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PVI_URL}/duplicate/search", 
		"Snapshot=t210.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_add_header("If-None-Match", 
		"\"i18n/en-5a9a6ebac98d25fc12e2e16341f8ab99.json\"");

	web_url("en.json_2", 
		"URL={PV_Admin_URL}/assets/i18n/en.json", 
		"Resource=1", 
		"Referer={PV_Admin_URL}/", 
		"Snapshot=t211.inf", 
		LAST);

	lr_end_transaction("FollowUp_11_NavigatePVAdmin",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("FollowUp_12_Logout");

	web_reg_find("Search=Body",
		"Text=Login",
		LAST);

	web_url("Logout", 
		"URL={PV_Admin_URL}/logout", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={PV_Admin_URL}/", 
		"Snapshot=t212.inf", 
		"Mode=HTTP", 
		LAST);

	lr_end_transaction("FollowUp_12_Logout",LR_AUTO);

	lr_think_time(3);

	return 0;
}