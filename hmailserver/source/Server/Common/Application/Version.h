#pragma once

#define HMAILSERVER_VERSION "5.6.8"
#define HMAILSERVER_BUILD "2434.16"


/*
- Sub OnHELO(oClient) #153 https://github.com/hmailserver/hmailserver/issues/153
- Fixed Incorrect DEBUG logging for event 'OnDeliverMessage' #181 https://github.com/hmailserver/hmailserver/issues/181
- Include HTMLBody into IMAP TEXT search https://github.com/hmailserver/hmailserver/pull/193
- Fixed implicit conversion: "int" to "unsigned char" https://github.com/hmailserver/hmailserver/pull/204
- Faulty: SMTP 'Disconnect client after too many invalid commands' #160 https://github.com/hmailserver/hmailserver/issues/160
- SMTP server error "550 Unsupported ESMTP extension" on MAIL FROM:... AUTH=<> [with fix] #164 https://github.com/hmailserver/hmailserver/issues/164
- Remove 15GB backup limit #69 https://github.com/hmailserver/hmailserver/issues/69
- Speed up 'update hm_messages set messageflags' #221 https://github.com/hmailserver/hmailserver/issues/221
- https://www.hmailserver.com/forum/viewtopic.php?f=7&p=196733#p196733 (Ofice 2016 Read-Receipt Bug)
- Add Return-Path as topmost header before sending the message to SA (+ delete Return-Path header after the SA check completes) https://github.com/hmailserver/hmailserver/issues/116
- Experimental Sub OnClientLogon(oClient), New ClientInfo property oClient.Authenticated (Boolean)
- Handling of long UIDL response lists was too slow. #93 https://github.com/hmailserver/hmailserver/issues/93
- When calling SpamAssassin and there was a connection failure, sometimes temporary files were left behind #100 https://github.com/hmailserver/hmailserver/issues/100
- SURBL detection properly fails to detect url's ending with a query string #108 https://github.com/hmailserver/hmailserver/issues/108
- If a route is set up, but the recipient does not match an address in the route address list, the domain catch-all should be used if specified. #74 https://github.com/hmailserver/hmailserver/issues/74
- Fix ExternalFetcher DELE when no RETR #253 https://github.com/hmailserver/hmailserver/issues/253
*/

