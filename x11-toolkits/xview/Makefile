# New ports collection makefile for:	XView
# Date created:		22 November 1994
# Whom:			ljo (orig)
#
# $FreeBSD$
#

PORTNAME=	xview
PORTVERSION=	3.2.1
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.efd.lth.se/pub/X11/ \
		ftp://ftp.uni-heidelberg.de/pub/X11/contrib/libraries/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav
DISTNAME=	xview3.2p1-X11R6

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X Window-System-based Visual/Integrated Environment for Workstations

REINPLACE_ARGS=	-i ""
USE_IMAKE=	yes
INSTALLS_SHLIB=	yes
IMAKEINCLUDE=	"-I${X11BASE}/lib/X11/config -I${WRKSRC}/config"
MAKE_ENV+=	IMAKEINCLUDE=${IMAKEINCLUDE}
ALL_TARGET=	World

MAN1=		msgfmt.1 xgettext.1 xview.1

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's+/usr/X11R6+${PREFIX}+;' \
	  ${WRKSRC}/config/XView.cf
	@${REINPLACE_CMD} -e 's+/usr/X11/+${X11BASE}/+g;' \
	  ${WRKSRC}/clients/olwm/screen.c
	@${REINPLACE_CMD} -e 's+/usr/lib+${PREFIX}/lib+g;' \
	  ${WRKSRC}/clients/olwmslave/help_file.c \
	  ${WRKSRC}/lib/libxview/help/help_file.c \
	  ${WRKSRC}/lib/libxview/misc/gettext.h \
	  ${WRKSRC}/lib/libxview/textsw/txt_e_menu.c

pre-configure:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
	's|^#endif.*$$|#endif|;s|^#else.*$$|#else|;\
	s|^/\*\*/#*|XCOMM |'

post-install:
.if !defined{NOPORTDOCS}
	@(cd ${WRKSRC}/doc; ${MAKE} install)
.endif

.include <bsd.port.post.mk>
