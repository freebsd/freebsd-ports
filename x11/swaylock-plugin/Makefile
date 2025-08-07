DISTVERSION=	1.8.3
PORTREVISION=	0
PKGNAMESUFFIX=	-plugin

COMMENT=	Screen locker for Wayland with background plugin support
WWW=		https://github.com/mstoeckl/swaylock-plugin

MASTERDIR=	${.CURDIR}/../swaylock
DESCR=		${.CURDIR}/pkg-descr
DISTINFO_FILE=	${.CURDIR}/distinfo

GH_ACCOUNT=	mstoeckl
GH_PROJECT=	${PORTNAME}${PKGNAMESUFFIX}
MESON_ARGS=	-Dlogind=disabled

pre-patch:
# Compat to apply patch-pam_swaylock "as is"
	${MV} ${WRKSRC}/pam/${PKGBASE} ${WRKSRC}/pam/${PORTNAME}

post-patch:	slave-post-patch
slave-post-patch:
# Compat to apply patch-pam_swaylock "as is"
	-@${MV} ${WRKSRC}/pam/${PORTNAME}.orig ${WRKSRC}/pam/${PKGBASE}.orig
	@${MV} ${WRKSRC}/pam/${PORTNAME} ${WRKSRC}/pam/${PKGBASE}
# Skip building stub swaylock-sleep-watcher
	@${REINPLACE_CMD} -e '/^logind/s/,/, disabler: true,/' \
		${WRKSRC}/meson.build

post-install:
	@${REINPLACE_CMD} '/licenses/!s/${PORTNAME}/${PKGBASE}/' ${TMPPLIST}

.include "${MASTERDIR}/Makefile"
