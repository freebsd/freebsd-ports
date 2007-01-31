# New ports collection makefile for:	XView
# Date created:		22 November 1994
# Whom:			ljo (orig)
#
# $FreeBSD$
#

PORTNAME=	xview
PORTVERSION=	3.2.1
PORTREVISION=	6
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.efd.lth.se/pub/X11/ \
		ftp://ftp.uni-heidelberg.de/pub/X11/contrib/libraries/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav
DISTNAME=	xview3.2p1-X11R6

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X Window-System-based Visual/Integrated Environment for Workstations

BUILD_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

REINPLACE_ARGS=	-i ""
USE_IMAKE=	yes
USE_LDCONFIG=	yes
IMAKEINCLUDE=	"-I${X11BASE}/lib/X11/config -I${WRKSRC}/config"
MAKE_ENV+=	IMAKEINCLUDE=${IMAKEINCLUDE}
ALL_TARGET=	World
SUB_FILES=	pkg-message

X11BASE2FIX=	clients/olwm/screen.c clients/olwmslave/help_file.c		\
		lib/libxview/help/help_file.c lib/libxview/misc/gettext.h	\
		lib/libxview/textsw/txt_e_menu.c

MAN1=		xview.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's+/usr/X11R6+${PREFIX}+;' \
	  ${WRKSRC}/config/XView.cf
	@${REINPLACE_CMD} -e "s,CcCmd cc,CcCmd ${CC}," \
	  ${WRKSRC}/config/XView.tmpl
	@${REINPLACE_CMD} -e 's+/usr/X11/+${X11BASE}/+g;' \
	  ${WRKSRC}/clients/olwm/screen.c
	@${REINPLACE_CMD} -e 's+/usr/lib+${PREFIX}/lib+g;' \
	  ${WRKSRC}/clients/olwmslave/help_file.c \
	  ${WRKSRC}/lib/libxview/help/help_file.c \
	  ${WRKSRC}/lib/libxview/misc/gettext.h \
	  ${WRKSRC}/lib/libxview/textsw/txt_e_menu.c
	@${REINPLACE_CMD} -e "s,^MSG_UTIL,#MSG_UTIL," \
	  ${WRKSRC}/util/Imakefile

pre-configure:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
	's|^#endif.*$$|#endif|;s|^#else.*$$|#else|;\
	s|^/\*\*/#*|XCOMM |'
	${REINPLACE_CMD} -e 's+/usr/X11R6+${X11BASE}+'	\
		${X11BASE2FIX:C|^|${WRKSRC}/|}

post-install:
.if !defined{NOPORTDOCS}
	@(cd ${WRKSRC}/doc; ${MAKE} install)
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
