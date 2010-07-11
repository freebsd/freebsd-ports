# ex:ts=8
# New ports collection makefile for:	xclip
# Date created:			Dec 18, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xclip
PORTVERSION=	0.12
CATEGORIES=	x11
MASTER_SITES=	SF

MAINTAINER=	ports@eitanadler.com
COMMENT=	An interface to X selections ("the clipboard") from the command line

USE_AUTOTOOLS=	autoconf:262:env aclocal:19:env automake:19:env
USE_XORG=	x11 xmu
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		xclip.1 xclip-copyfile.1
PLIST_FILES=	bin/xclip bin/xclip-copyfile bin/xclip-cutfile bin/xclip-pastefile

pre-configure:
	@cd ${WRKSRC}; ./bootstrap

.include <bsd.port.mk>
