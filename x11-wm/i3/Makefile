# Created by: Dennis Herrmann <dhn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	i3
DISTVERSION=	4.4
CATEGORIES=	x11-wm
MASTER_SITES=	http://i3wm.org/downloads/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dhn

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	An improved dynamic tiling window manager

LICENSE=	BSD

BUILD_DEPENDS=	flex>=2.5.35:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	xcb:${PORTSDIR}/x11/libxcb \
		startup-notification:${PORTSDIR}/x11/startup-notification \
		xcb-util:${PORTSDIR}/x11/xcb-util \
		xcb-keysyms:${PORTSDIR}/x11/xcb-util-keysyms \
		xcb-icccm:${PORTSDIR}/x11/xcb-util-wm \
		ev:${PORTSDIR}/devel/libev \
		yajl:${PORTSDIR}/devel/yajl \
		cairo:${PORTSDIR}/graphics/cairo \
		pangocairo:${PORTSDIR}/x11-toolkits/pango \
		pcre:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	p5-IPC-Run>=0:${PORTSDIR}/devel/p5-IPC-Run \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-AnyEvent-I3>=0:${PORTSDIR}/devel/p5-AnyEvent-I3

USE_PERL5=	yes
USE_XORG=	x11 xcursor
USE_BISON=	build
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/i3 \
		bin/i3-config-wizard \
		bin/i3-dmenu-desktop \
		bin/i3-dump-log \
		bin/i3-input \
		bin/i3-migrate-config-to-v4 \
		bin/i3-msg \
		bin/i3-nagbar \
		bin/i3-sensible-editor \
		bin/i3-sensible-pager \
		bin/i3-sensible-terminal \
		bin/i3bar \
		etc/i3/config.sample \
		etc/i3/config.keycodes \

PLIST_DIRS=	etc/i3

MANUALS=	i3-config-wizard.1 i3-dmenu-desktop.1 \
		i3-dump-log.1 i3-input.1 \
		i3-migrate-config-to-v4.1 i3-msg.1 \
		i3-nagbar.1 i3-sensible-editor.1 \
		i3-sensible-pager.1 i3-sensible-terminal.1 \
		i3.1 i3bar.1

MAN1=	${MANUALS}

post-extract:
	@cd ${WRKSRC} && ${CP} i3.config config.sample
	@cd ${WRKSRC} && ${CP} i3.config.keycodes config.keycodes

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/src/config.c
	@${REINPLACE_CMD} -e 's|/usr/|${PREFIX}/|g' ${WRKSRC}/config.sample
	@${REINPLACE_CMD} -e 's|/usr/|${PREFIX}/|g' ${WRKSRC}/config.keycodes
	@${REINPLACE_CMD} -e 's|PREFIX|${PREFIX}/|g' ${WRKSRC}/man/Makefile
	@${REINPLACE_CMD} -e 's|/usr/|${PREFIX}/|g' ${WRKSRC}/man/i3.1
	@${REINPLACE_CMD} -e 's|/usr/|${PREFIX}/|g' ${WRKSRC}/man/i3-msg.1
	@${REINPLACE_CMD} -e 's|/usr/|${PREFIX}/|g' ${WRKSRC}/man/i3-input.1
	@${REINPLACE_CMD} -e 's|.SILENT||g' ${WRKSRC}/common.mk
	@${REINPLACE_CMD} -e 's|-Iinclude|-Iinclude -Isrc|g' \
			  -e 's|flex|${LOCALBASE}/bin/flex|g' \
			  -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/common.mk

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
.for i in i3-config-wizard i3-dump-log i3-input i3-msg i3-nagbar i3bar
	${INSTALL_SCRIPT} ${WRKSRC}/$i/$i ${PREFIX}/bin/
.endfor
.for i in i3-dmenu-desktop i3-sensible-editor i3-sensible-pager \
	i3-sensible-terminal i3-migrate-config-to-v4
	${INSTALL_SCRIPT} ${WRKSRC}/$i ${PREFIX}/bin/
.endfor
	@${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/config.sample ${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/config.keycodes ${PREFIX}/etc/${PORTNAME}
.for i in ${MANUALS}
	${INSTALL_MAN} ${WRKSRC}/man/${i} ${MANPREFIX}/man/man1/
.endfor

	@${ECHO_MSG} "======================================================================================"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	${PORTNAME} needs a config file! You can find an example in ${PREFIX}/etc/${PORTNAME}"
	@${ECHO_MSG} "	Please rename it to ${PREFIX}/etc/${PORTNAME}/config"
	@${ECHO_MSG} "	For more information read the manpage :)"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "======================================================================================"

.include <bsd.port.mk>
