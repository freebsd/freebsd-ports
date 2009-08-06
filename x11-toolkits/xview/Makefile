# New ports collection makefile for:	XView
# Date created:		22 November 1994
# Whom:			ljo (orig)
#
# $FreeBSD$
#

PORTNAME=	xview
PORTVERSION=	3.2.1
PORTREVISION=	10
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.efd.lth.se/pub/X11/ \
		ftp://ftp.uni-heidelberg.de/pub/X11/contrib/libraries/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav
DISTNAME=	xview3.2p1-X11R6

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X Window-System-based Visual/Integrated Environment for Workstations

MAKE_JOBS_UNSAFE=	yes

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale

ONLY_FOR_ARCHS=	i386
REINPLACE_ARGS=	-i ""
USE_IMAKE=	yes
USE_XORG=	x11
USE_LDCONFIG=	yes
IMAKEINCLUDE=	"-I${LOCALBASE}/lib/X11/config -I${WRKSRC}/config"
MAKE_ENV+=	IMAKEINCLUDE=${IMAKEINCLUDE}
ALL_TARGET=	World
SUB_FILES=	pkg-message

MAN1=		xview.1

X11BASE2FIX=	clients/olwmslave/help_file.c	lib/libxview/help/help_file.c	\
		lib/libxview/misc/gettext.h	lib/libxview/textsw/txt_e_menu.c

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 800089
CFLAGS+=	-DCOMPAT_43TTY
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's+/usr/local+${PREFIX}+;' \
	  ${WRKSRC}/config/XView.cf
	@${REINPLACE_CMD} -e "s,CcCmd cc,CcCmd ${CC}," \
	  ${WRKSRC}/config/XView.tmpl
	@${REINPLACE_CMD} -e 's+/usr/X11/+${LOCALBASE}/+g;' \
	  ${WRKSRC}/clients/olwm/screen.c
	${REINPLACE_CMD} -e 's+/usr/lib+${PREFIX}/lib+'	\
		${X11BASE2FIX:C|^|${WRKSRC}/|}
	@${REINPLACE_CMD} -e "s,^MSG_UTIL,#MSG_UTIL," \
	  ${WRKSRC}/util/Imakefile
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
	's|^#endif.*$$|#endif|;s|^#else.*$$|#else|;\
	s|^/\*\*/#*|XCOMM |'

post-install:
.if !defined{NOPORTDOCS}
	@(cd ${WRKSRC}/doc; ${MAKE} install)
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
