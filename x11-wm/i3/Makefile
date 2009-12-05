# New ports collection makefile for:	i3
# Date created:		2009-04-19
# Whom:			Dennis Herrmann <dhn@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	i3
DISTVERSION=	3.d
CATEGORIES=	x11-wm
MASTER_SITES=	http://i3.zekjur.net/downloads/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dhn

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	An improved dynamic tiling window manager

LIB_DEPENDS=	xcb.2:${PORTSDIR}/x11/libxcb \
		xcb-event.1:${PORTSDIR}/x11/xcb-util \
		ev.3:${PORTSDIR}/devel/libev

USE_XORG=	x11
USE_BISON=	yes
USE_XLIB=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/i3 \
		bin/i3-msg \
		bin/i3-input \
		etc/i3/config.sample \
		etc/i3/welcome
PLIST_DIRS=	etc/i3

MAN1=	i3.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=	Does not compile on FreeBSD 6.X
.endif

post-extract:
	@cd ${WRKSRC} && ${CP} i3.config config.sample
	@cd ${WRKSRC} && ${CP} i3.welcome welcome

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/src/config.c
	@${REINPLACE_CMD} -e 's|/usr/|${PREFIX}/|g' ${WRKSRC}/config.sample
	@${REINPLACE_CMD} -e 's|/usr/|${PREFIX}/|g' ${WRKSRC}/welcome
	@${REINPLACE_CMD} -e 's|PREFIX|${PREFIX}/|g' ${WRKSRC}/man/Makefile
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/common.mk
	@${REINPLACE_CMD} -e 's|/usr/|${PREFIX}/|g' ${WRKSRC}/man/i3.1
	@${REINPLACE_CMD} -e 's|/usr/|${PREFIX}/|g' ${WRKSRC}/man/i3-msg.1
	@${REINPLACE_CMD} -e 's|/usr/|${PREFIX}/|g' ${WRKSRC}/man/i3-input.1
	@${REINPLACE_CMD} -e 's|.SILENT||g' ${WRKSRC}/common.mk
	@${REINPLACE_CMD} -e 's|-Iinclude|-Iinclude -Isrc|g' ${WRKSRC}/common.mk

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}-msg/${PORTNAME}-msg ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}-input/${PORTNAME}-input ${PREFIX}/bin/
	@${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/config.sample ${PREFIX}/etc/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/welcome ${PREFIX}/etc/${PORTNAME}/welcome
	${INSTALL_MAN} ${WRKSRC}/man/${MAN1} ${MANPREFIX}/man/man1

	@${ECHO_MSG} "======================================================================================"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	${PORTNAME} need a config file! A example do you found on ${PREFIX}/etc/${PORTNAME}"
	@${ECHO_MSG} "	Please rename it in ${PREFIX}/etc/${PORTNAME}/config"
	@${ECHO_MSG} "	For more information read the manpage :)"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "======================================================================================"

.include <bsd.port.post.mk>
