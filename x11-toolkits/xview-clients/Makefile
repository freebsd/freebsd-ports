# Created by: ljo (orig)
# $FreeBSD$

PORTNAME=	xview-clients
PORTVERSION=	3.2.1.4.19c
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.physionet.org/physiotools/xview/src/ \
		http://komquats.com/distfiles/ \
		LOCAL/cy
DISTNAME=	xview-3.2p1.4-19c
# EXTRACT_ONLY=	# empty

MAINTAINER=	cy@FreeBSD.org
COMMENT=	OpenLook applications and man pages

CONFLICTS=	props-1.0

MAKE_JOBS_UNSAFE=	yes
PATCHDIR=	${PORTSDIR}/x11-toolkits/xview/files
LIB_DEPENDS=	libxview.so:x11-toolkits/xview

USES=		imake
USE_XORG=	x11 xext
ALL_TARGET=	Clients

X11BASE2FIX=	clients/olwmslave/help_file.c lib/libxview/help/help_file.c \
		lib/libxview/misc/gettext.h lib/libxview/textsw/txt_e_menu.c

CFLAGS+=	-DCOMPAT_43TTY

IMAKECPPFLAGS+=	-DXVDestDir=${STAGEDIR}${PREFIX}

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

do-install:
	@cd ${WRKSRC}/clients; ${MAKE} DESTDIR=${STAGEDIR} install install.man
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/help
	@${INSTALL_DATA} ${WRKSRC}/misc/support/textedit.info ${STAGEDIR}${PREFIX}/lib/help/textedit.info

.include <bsd.port.mk>
