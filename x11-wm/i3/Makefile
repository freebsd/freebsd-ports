# New ports collection makefile for:	i3
# Date created:		2009-04-19
# Whom:			Dennis Herrmann <dhn@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	i3
DISTVERSION=	3.b
CATEGORIES=	x11-wm
MASTER_SITES=	http://i3.zekjur.net/downloads/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dhn

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	An improved dynamic tiling window manager

BUILD_DEPENDS=	asciidoc:${PORTSDIR}/textproc/asciidoc \
		readlink:${PORTSDIR}/sysutils/readlink \
		xmlto:${PORTSDIR}/textproc/xmlto
LIB_DEPENDS=	xcb.2:${PORTSDIR}/x11/libxcb \
		xcb-event.1:${PORTSDIR}/x11/xcb-util \
		ev.3:${PORTSDIR}/devel/libev

USE_XORG=	x11
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/i3 \
		etc/i3/config.sample
PLIST_DIRS=	etc/i3

MAN1=	i3.1

post-extract:
	@cd ${WRKSRC} && ${CP} i3.config config.sample

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/src/config.c
	@${REINPLACE_CMD} -e 's|/usr/|${PREFIX}|g' ${WRKSRC}/config.sample
	@${REINPLACE_CMD} -e 's|PREFIX|${PREFIX}|g' ${WRKSRC}/man/Makefile

# Create the manpage
post-build:
	@cd ${WRKSRC} && ${GMAKE} -C man

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	@${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/config.sample ${PREFIX}/etc/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/man/${MAN1} ${MANPREFIX}/man/man1

	@${ECHO_MSG} "======================================================================================"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	${PORTNAME} need a config file! A example do you found on ${PREFIX}/etc/${PORTNAME}"
	@${ECHO_MSG} "	Please rename it in ${PREFIX}/etc/${PORTNAME}/config"
	@${ECHO_MSG} "	For more information read the manpage :)"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "======================================================================================"

.include <bsd.port.mk>
