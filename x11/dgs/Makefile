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
MANN=		dpsexec.man xepsf.man
INSTALLDIRS=	gs DPS/clients/pswrap \
		DPS/demos/dpsexec DPS/demos/xepsf

.include <bsd.port.pre.mk>

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

.if ${X_WINDOW_SYSTEM:L} != xfree86-4
INSTALLDIRS+=	DPS/clients/makepsres DPS/demos/texteroids
MANN+=		makepsres.man
.endif

.if ${X_WINDOW_SYSTEM:L} == xfree86-3
PLIST_SUB+=	WITH_XORG=""
PLIST_SUB+=	WITH_XFREE4=""
.else
PLIST_SUB+=	WITH_XORG="@comment "

.if ${X_WINDOW_SYSTEM:L} == xorg
INSTALLDIRS+=	DPS/lib/dpstk DPS/lib/psres
PLIST_SUB+=	WITH_XFREE4=""
.else
PLIST_SUB+=	WITH_XFREE4="@comment "
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dgs-config ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/dpsnx.agent ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/path_dps.m4 ${PREFIX}/share/aclocal/
	${INSTALL_MAN} ${WRKSRC}/dpsnx.agent.1 ${PREFIX}/man/man1/
.for i in ${INSTALLDIRS}
	@(cd ${INSTALL_WRKSRC}/${i} && ${SETENV} ${MAKE_ENV} \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endfor

.endif

.include <bsd.port.post.mk>
