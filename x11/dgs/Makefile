# Created by: Yukihiro Nakai <Nakai@technologist.com>
# $FreeBSD$

PORTNAME=	dgs
PORTVERSION=	0.5.9.1
PORTREVISION=	11
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	../old-gnu/dgs

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A display ghostscript system

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff

USE_GHOSTSCRIPT_RUN=	yes
USE_XORG=	xt sm ice xext x11
USE_GMAKE=	yes
USE_GNOME=	glib12
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
WRKSRC=		${WRKDIR}/${PORTNAME}-0.5.9
MAKE_JOBS_UNSAFE=	yes

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
	-e 's|freebsd2\*)|freebsd2.\*)|' -e 's|freebsd1\*)|freebsd1.\*)|' \
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
