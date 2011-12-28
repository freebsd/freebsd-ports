# New ports collection makefile for:	i3status
# Date created:		2011-12-08
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	i3status
PORTVERSION=	2.4
CATEGORIES=	x11
MASTER_SITES=	http://i3wm.org/i3status/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Small program for generating a status bar

LICENSE=	BSD

LIB_DEPENDS=	confuse.0:${PORTSDIR}/devel/libconfuse

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_BZIP2=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/i3status \
		etc/i3status/config.sample
PLIST_DIRSTRY=	etc/i3status
MAN1=	i3status.1

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/i3status.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/i3status ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/man/i3status.1 ${MANPREFIX}/man/man1
	${MKDIR} ${PREFIX}/etc/i3status
	${INSTALL_MAN} ${WRKSRC}/i3status.conf ${PREFIX}/etc/i3status/config.sample

.include <bsd.port.mk>
