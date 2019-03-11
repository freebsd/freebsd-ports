# Created by: ljo (orig)
# $FreeBSD$

PORTNAME=	xview
PORTVERSION=	3.2.1.4.19c
PORTREVISION=	4
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.physionet.org/physiotools/xview/src/ \
		http://komquats.com/distfiles/ \
		LOCAL/cy
DISTNAME=	xview-3.2p1.4-19c

MAINTAINER=	cy@FreeBSD.org
COMMENT=	X Window-System-based Visual/Integrated Environment for Workstations

MAKE_JOBS_UNSAFE=	yes

BUILD_DEPENDS=	mkfontscale:x11-fonts/mkfontscale

ONLY_FOR_ARCHS=	i386
REINPLACE_ARGS=	-i ""
USES=		imake
USE_XORG=	x11
USE_LDCONFIG=	yes
IMAKEINCLUDE=	"-I${WRKSRC}/config -I${LOCALBASE}/lib/X11/config"
MAKE_ENV+=	IMAKEINCLUDE=${IMAKEINCLUDE}
ALL_TARGET=	World
SUB_FILES=	pkg-message
CFLAGS+=	-Wno-return-type -DCOMPAT_43TTY
DESTDIRNAME=	NONEXISTENT

X11BASE2FIX=	clients/olwmslave/help_file.c	lib/libxview/help/help_file.c	\
		lib/libxview/misc/gettext.h	lib/libxview/textsw/txt_e_menu.c

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MV} ${WRKSRC}/xview.man ${WRKSRC}/XView.man

pre-configure:
	@${REINPLACE_CMD} -e 's+/usr/local+${PREFIX}+;' \
	  ${WRKSRC}/config/XView.cf
	@${REINPLACE_CMD} -e "s,CcCmd cc,CcCmd ${CC}," \
	  ${WRKSRC}/config/XView.tmpl
	@${REINPLACE_CMD} -e 's+/usr/X11/+${PREFIX}/+g;' \
	  ${WRKSRC}/clients/olwm/screen.c
	${REINPLACE_CMD} -e 's+/usr/lib+${PREFIX}/lib+'	\
		${X11BASE2FIX:C|^|${WRKSRC}/|}
	@${REINPLACE_CMD} -e "s,^MSG_UTIL,#MSG_UTIL," \
	  ${WRKSRC}/util/Imakefile
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
	's|^#endif.*$$|#endif|;s|^#else.*$$|#else|;\
	s|^/\*\*/#*|XCOMM |'

pre-install:
	@${FIND} ${WRKSRC} -type f -name Makefile | ${XARGS} ${REINPLACE_CMD} -e '/XVDESTDIR = /s+${PREFIX}+${STAGEDIR}${PREFIX}+'
	@${FIND} ${WRKSRC}/config ${WRKSRC}/fonts -type f -name Makefile | ${XARGS} ${REINPLACE_CMD} -e '/PROJECTROOT = /!s+${PREFIX}+${STAGEDIR}${PREFIX}+g'

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/lib/help/clock.info
	@${RM} ${STAGEDIR}${PREFIX}/lib/help/olwm.info
	@${RM} ${STAGEDIR}${PREFIX}/lib/help/props.info
	@${RM} ${STAGEDIR}${PREFIX}/lib/help/textedit.info

post-install-DOCS-on:
	@(cd ${WRKSRC}/doc; ${MAKE} install)

.include <bsd.port.mk>
