# New ports collection makefile for:	i3
# Date created:		2009-04-19
# Whom:			Dennis Herrmann <dhn@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	i3
DISTVERSION=	4.1.1
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://i3wm.org/downloads/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dhn

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	An improved dynamic tiling window manager

BUILD_DEPENDS=	flex>=2.5.35:${PORTSDIR}/textproc/flex \
		pcre>=0:${PORTSDIR}/devel/pcre
LIB_DEPENDS=	xcb.2:${PORTSDIR}/x11/libxcb \
		startup-notification-1.0:${PORTSDIR}/x11/startup-notification \
		xcb-util.0:${PORTSDIR}/x11/xcb-util \
		xcb-keysyms.1:${PORTSDIR}/x11/xcb-util-keysyms \
		xcb-icccm.4:${PORTSDIR}/x11/xcb-util-wm \
		ev.4:${PORTSDIR}/devel/libev \
		yajl.2:${PORTSDIR}/devel/yajl
RUN_DEPENDS=	${SITE_PERL}/IPC/Run.pm:${PORTSDIR}/devel/p5-IPC-Run

USE_XORG=	x11 xcursor
USE_BISON=	build
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/i3 \
		bin/i3-config-wizard \
		bin/i3-input \
		bin/i3-msg \
		bin/i3-nagbar \
		bin/i3bar \
		bin/i3-migrate-config-to-v4 \
		bin/i3-sensible-editor \
		bin/i3-sensible-pager \
		bin/i3-sensible-terminal \
		bin/i3-wsbar \
		etc/i3/config.sample \
		etc/i3/welcome

PLIST_DIRS=	etc/i3

MANUALS=	i3-config-wizard.1 i3-input.1 i3-migrate-config-to-v4.1 i3-msg.1 i3-nagbar.1 i3-wsbar.1 i3.1

MAN1=	${MANUALS}

.include <bsd.port.pre.mk>

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
	@${REINPLACE_CMD} -e 's|flex|${LOCALBASE}/bin/flex|g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
.for i in i3-config-wizard i3-input i3-msg i3-nagbar i3bar
	${INSTALL_SCRIPT} ${WRKSRC}/$i/$i ${PREFIX}/bin/
.endfor
.for i in i3-sensible-editor i3-sensible-pager i3-sensible-terminal i3-wsbar i3-migrate-config-to-v4
	${INSTALL_SCRIPT} ${WRKSRC}/$i ${PREFIX}/bin/
.endfor
	@${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/config.sample ${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/welcome ${PREFIX}/etc/${PORTNAME}/welcome
.for i in ${MANUALS}
	${INSTALL_MAN} ${WRKSRC}/man/${i} ${MANPREFIX}/man/man1/
.endfor

	@${ECHO_MSG} "======================================================================================"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	${PORTNAME} need a config file! A example do you found on ${PREFIX}/etc/${PORTNAME}"
	@${ECHO_MSG} "	Please rename it in ${PREFIX}/etc/${PORTNAME}/config"
	@${ECHO_MSG} "	For more information read the manpage :)"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "======================================================================================"

.include <bsd.port.post.mk>
