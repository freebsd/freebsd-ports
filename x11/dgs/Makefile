# New ports collection makefile for:   dgs
# Date created:        22 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	dgs
PORTVERSION=	0.5.9.1
PORTREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	../old-gnu/dgs

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A display ghostscript system

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff

USE_GHOSTSCRIPT_RUN=	yes
USE_XORG=	xt sm ice xext x11
USE_GMAKE=	yes
USE_GNOME=	glib12
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool:15
WRKSRC=		${WRKDIR}/${PORTNAME}-0.5.9

MAN1=		dgs.1 dpsnx.agent.1
MANN=		dpsexec.man makepsres.man xepsf.man
INSTALLDIRS=	gs DPS/clients/makepsres DPS/clients/pswrap \
		DPS/demos/dpsexec DPS/demos/texteroids DPS/demos/xepsf \
		DPS/lib/dpstk DPS/lib/psres DPS/lib/dps DPS/include/DPS

.include <bsd.port.pre.mk>

pre-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} \
		${REINPLACE_CMD} -e 's|manm|mann|g'

post-patch:
	${REINPLACE_CMD} -e 's|echo aout|echo elf|' \
		${WRKSRC}/DPS/ltconfig

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dgs-config ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/dpsnx.agent ${PREFIX}/bin/
#	${INSTALL_DATA} ${WRKSRC}/path_dps.m4 ${PREFIX}/share/aclocal/
	${INSTALL_MAN} ${WRKSRC}/dpsnx.agent.1 ${PREFIX}/man/man1/
.for i in ${INSTALLDIRS}
	@(cd ${INSTALL_WRKSRC}/${i} && ${SETENV} ${MAKE_ENV} \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endfor

.include <bsd.port.post.mk>
