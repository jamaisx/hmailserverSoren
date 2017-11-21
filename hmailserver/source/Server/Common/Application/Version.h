#pragma once

#define HMAILSERVER_VERSION "5.6.7"
#define HMAILSERVER_BUILD "2420.11"


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
*/

