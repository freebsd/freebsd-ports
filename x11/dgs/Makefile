# New ports collection makefile for:   dgs
# Date created:        22 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	dgs
PORTVERSION=	0.5.9.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	dgs

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A display ghostscript system

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_GHOSTSCRIPT_RUN=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	glib12
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-0.5.9

MAN1=		dgs.1 dpsnx.agent.1
MANN=		dpsexec.man makepsres.man xepsf.man

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xfree86-3
IGNORE=		is included in XFree86 4.x and above
.endif

pre-fetch:
.if !defined(WITH_GHOSTSCRIPT_AFPL) || ${WITH_GHOSTSCRIPT_AFPL} != yes
	@${ECHO} ""
	@${ECHO} "      Define WITH_GHOSTSCRIPT_AFPL=yes to use"
	@${ECHO} "      AFPL Postscript interpreter instead of GNU one"
	@${ECHO} ""
.endif

pre-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} \
		${REINPLACE_CMD} -e 's|manm|mann|g'

.include <bsd.port.post.mk>
