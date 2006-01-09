# New ports collection makefile for:   jwm
# Date created:        26 DEC 2005
# Whom:                babak@farrokhi.net
#
# $FreeBSD$
#

PORTNAME=	jwm
PORTVERSION=	1.2
CATEGORIES=	x11-wm
MASTER_SITES=	http://joewing.net/programs/jwm/ \
		http//bsdgeek.no-ip.org/jwm/

MAINTAINER=	babak@farrokhi.net
COMMENT=	Joe's Window Manager

USE_X_PREFIX=	yes
USE_XPM=	yes
HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX} --enable-icons --enable-png \
			--enable-xpm --enable-shape --enable-xinerama \
			--enable-xft --enable-xrender

MAN1=		jwm.1
PLIST_FILES=	bin/jwm etc/system.jwmrc

post-patch:
	    @${REINPLACE_CMD} -e 's,^CC =,CC ?=,' \
	        -e 's,^CFLAGS =,CFLAGS +=,' \
		${WRKSRC}/src/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/jwm ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/example.jwmrc ${PREFIX}/etc/system.jwmrc
	${INSTALL_MAN} ${WRKSRC}/jwm.1 ${MANPREFIX}/man/man1/

.include <bsd.port.mk>
