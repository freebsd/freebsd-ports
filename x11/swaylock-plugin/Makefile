DISTVERSIONPREFIX=	# empty
DISTVERSION=	s20231230
DISTVERSIONSUFFIX=	-0-gdf71de5
PORTREVISION=	0
PKGNAMESUFFIX=	-plugin

COMMENT=	Screen locker for Wayland with background plugin support
WWW=		https://github.com/mstoeckl/swaylock-plugin

MASTERDIR=	${.CURDIR}/../swaylock
DESCR=		${.CURDIR}/pkg-descr
DISTINFO_FILE=	${.CURDIR}/distinfo

GH_ACCOUNT=	mstoeckl
GH_PROJECT=	${PORTNAME}${PKGNAMESUFFIX}

pre-patch:
# Compat to apply patch-pam_swaylock "as is"
	${MV} ${WRKSRC}/pam/${PKGBASE} ${WRKSRC}/pam/${PORTNAME}

post-patch:	slave-post-patch
slave-post-patch:
# Compat to apply patch-pam_swaylock "as is"
	-@${MV} ${WRKSRC}/pam/${PORTNAME}.orig ${WRKSRC}/pam/${PKGBASE}.orig
	@${MV} ${WRKSRC}/pam/${PORTNAME} ${WRKSRC}/pam/${PKGBASE}
# Avoid subdirs to match regular swaylock
	@${REINPLACE_CMD} "s,\(rename: \['\)[^/]*/,\1," \
		${WRKSRC}/completions/meson.build
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=275328
	@${REINPLACE_CMD} -e 's/_POSIX_C_SOURCE 200809L/_XOPEN_SOURCE 700/' \
		${WRKSRC}/main.c

post-install:
	@${REINPLACE_CMD} '/licenses/!s/${PORTNAME}/${PKGBASE}/' ${TMPPLIST}

.include "${MASTERDIR}/Makefile"
